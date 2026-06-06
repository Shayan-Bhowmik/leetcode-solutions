class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int leftSum = 0;
        int rightSum = 0;

        vector<int> ans;

        for(int i=0; i<n; i++) {
            rightSum += nums[i];
        }

        for(int i=0; i<n; i++) {
            if(i == n-1) {
                rightSum = 0;
            }
            else{
                rightSum -= nums[i];
            }

            if(i == 0) {
                leftSum = 0;
            }
            else{
                leftSum += nums[i-1];
            }

            int sub = abs(leftSum - rightSum);
            ans.push_back(sub);
        }
        return ans;
    }
};