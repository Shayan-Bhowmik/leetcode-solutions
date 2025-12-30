class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int start = 0; start < n; start++) {
            int currSum = 0; 
            for(int end = start; end < n; end++) {
                currSum = currSum + nums[end];
                maxSum = max(currSum, maxSum);
            }
        }
        return maxSum;
    }
};