class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int product=1;
            for(int j=0; j<n; j++) {
                if(i != j) {
                    product = product * nums[j];
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};