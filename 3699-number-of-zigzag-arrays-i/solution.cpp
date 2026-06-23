class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;

        int m = r - l + 1;

        if(n == 1) {
            return m;
        }

        vector<long long> down(m + 1, 0);
        vector<long long> up(m + 1, 0);

        for(int i = 1; i <= m; i++) {
            down[i] = i - 1;
            up[i] = m - i;
        }

        vector<long long> prefUp(m + 1, 0);
        vector<long long> suffDown(m + 2, 0);

        vector<long long> nextDown(m + 1, 0);
        vector<long long> nextUp(m + 1, 0);

        for(int k = 2; k < n; k++) {

            prefUp[0] = 0;

            for(int i = 1; i <= m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % mod;
            }

            suffDown[m + 1] = 0;

            for(int j = m; j >= 1; j--) {
                suffDown[j] = (suffDown[j + 1] + down[j]) % mod;
            }

            for(int z = 1; z <= m; z++) {
                nextDown[z] = prefUp[z - 1];
                nextUp[z] = suffDown[z + 1];
            }

            swap(down, nextDown);
            swap(up, nextUp);
        }

        long long ans = 0;

        for(int i = 1; i <= m; i++) {
            ans = (ans + down[i] + up[i]) % mod;
        }

        return (int)ans;
    }
};