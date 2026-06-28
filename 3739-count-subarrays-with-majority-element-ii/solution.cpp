class Solution {
public:
    class BIT {
    public:
        vector<int> bit;
        int n;

        BIT(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        BIT bit(2 * n + 2);

        int prefix = n + 1;  // Offset to handle negative prefix sums
        bit.update(prefix, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            ans += bit.query(prefix - 1);
            bit.update(prefix, 1);
        }

        return ans;
    }
};