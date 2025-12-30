class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;

        for(int i: nums) {
            curr_sum = curr_sum + i;
            max_sum = max(curr_sum, max_sum);
            if(curr_sum < 0) {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};
