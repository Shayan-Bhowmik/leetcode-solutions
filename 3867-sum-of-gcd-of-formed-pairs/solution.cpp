class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int currGcd = nums[0];
        int maxGcd=0;
        for (int i = 0; i < n; i++) {
            maxGcd = max(maxGcd, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxGcd);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        int right=n-1;
        int left=0;
        long long sum=0;
        long long gcdpair=0;

        while(left < right) {
            gcdpair = gcd(prefixGcd[left], prefixGcd[right]);
            sum += gcdpair;
            right--;
            left++;
        }
        return sum;
    }
};