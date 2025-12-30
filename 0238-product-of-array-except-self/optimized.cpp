class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int j=n-2; j>=0; j--) {
            suffix[j] = suffix[j+1] * nums[j+1];
        }

        for(int k=0; k<n; k++) {
            ans[k] = prefix[k] * suffix[k];
        }

        return ans;
    }
};