class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<long long> f(MAXX, 0);

        for (int x : nums) f[x] = 1;

        for (int len = 1; len < MAXX; len <<= 1) {
            for (int i = 0; i < MAXX; i += (len << 1)) {
                for (int j = 0; j < len; j++) {
                    long long a = f[i + j];
                    long long b = f[i + j + len];
                    f[i + j] = a + b;
                    f[i + j + len] = a - b;
                }
            }
        }

        for (int i = 0; i < MAXX; i++)
            f[i] = f[i] * f[i] * f[i];

        for (int len = 1; len < MAXX; len <<= 1) {
            for (int i = 0; i < MAXX; i += (len << 1)) {
                for (int j = 0; j < len; j++) {
                    long long a = f[i + j];
                    long long b = f[i + j + len];
                    f[i + j] = (a + b) / 2;
                    f[i + j + len] = (a - b) / 2;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < MAXX; i++) {
            if (f[i] > 0) ans++;
        }

        return ans;
    }
};