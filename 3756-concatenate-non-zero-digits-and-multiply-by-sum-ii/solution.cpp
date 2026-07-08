class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> power10(n + 1, 1);
        
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        vector<int> prefixSum(n + 1, 0);

        vector<int> prefixNonZero(n + 1, 0);

        vector<long long> prefixNumber(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i] + digit;
            prefixNonZero[i + 1] = prefixNonZero[i] + (digit != 0);

            if (digit != 0) {
                prefixNumber[i + 1] = (prefixNumber[i] * 10 + digit) % MOD;
            } else {
                prefixNumber[i + 1] = prefixNumber[i];
            }
        }

        vector<int> answer;

        for (auto &query : queries) {
            int left = query[0];
            int right = query[1];

            int digitSum = prefixSum[right + 1] - prefixSum[left];

            int nonZeroCount = prefixNonZero[right + 1] - prefixNonZero[left];
            long long number =
                (prefixNumber[right + 1]
                - (prefixNumber[left] * power10[nonZeroCount]) % MOD
                + MOD) % MOD;

            answer.push_back((number * digitSum) % MOD);
        }

        return answer;
    }
};