class Solution {
public:
    string s;

    long long dpCount[20][2][2][11][11];
    long long dpWave[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    pair<long long, long long> solveDP(int pos, int tight, int started, int prev1, int prev2) {
        if(pos == s.length()) {
            return{1, 0};
        }

        if(vis[pos][tight][started][prev1][prev2]) {
            return {dpCount[pos][tight][started][prev1][prev2], dpWave[pos][tight][started][prev1][prev2]};
        }

        vis[pos][tight][started][prev1][prev2] = true;

        long long totalCount = 0;
        long long totalWave = 0;

        int limit;

        if(tight) {
            limit = s[pos] - '0';
        }
        else{
            limit = 9;
        }

        for(int digit=0; digit<=limit; digit++) {
            int newTight;

            if(tight && digit == limit) {
                newTight=1;
            }
            else{
                newTight=0;
            }

            if(!started && digit==0) {
                auto next = solveDP(pos+1, newTight, 0, 10, 10);

                totalCount = totalCount + next.first;
                totalWave = totalWave + next.second;
            }

            else if(!started) {
                auto next = solveDP(pos+1, newTight, 1, digit, 10);
                    totalCount += next.first;
                    totalWave += next.second;
            }

            else{
                int add = 0;

                if(prev2 != 10) {
                    bool peak = (prev1 > prev2 && prev1 > digit);

                    bool valley = (prev1 < prev2 && prev1 < digit);

                    if(peak || valley) {
                        add = 1;
                    }
                }

                auto next = solveDP(pos+1, newTight, 1, digit, prev1);

                totalCount += next.first;
                totalWave = totalWave + next.second + (long long)add * next.first;
            }
        }
        dpCount[pos][tight][started][prev1][prev2] = totalCount;
        dpWave[pos][tight][started][prev1][prev2] = totalWave;

        return {totalCount, totalWave};
    }

    long long getAnswer(long long x) {

        if(x <= 0) {
            return 0;
        }

        s = to_string(x);

        memset(vis, false, sizeof(vis));

        return solveDP(0, 1, 0, 10, 10).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return getAnswer(num2) - getAnswer(num1 - 1);
    }
};