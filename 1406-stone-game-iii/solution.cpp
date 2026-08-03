class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(i>=n) {
            return 0;
        }

        if(dp[i]!=INT_MIN) {
            return dp[i];
        }
        int best=INT_MIN;
        int sum=0;

        for(int j=1; j<=3; j++) {
            if(i+j-1>=n) {
                break;
            }
            sum += stoneValue[i+j-1];
            best=max(best, sum-solve(i+j, stoneValue));
        }
        dp[i]=best;
        return dp[i];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size(), INT_MIN);

        int diff = solve(0, stoneValue);

        if(diff>0) {
            return "Alice";
        }else if(diff < 0) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }
};