class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score1 = 0;
        int score2 = 0;

        bool active = true;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] % 2 != 0) {
                if(active == true) {
                    active = false;
                }
                else {
                    active = true;
                }
            }
            if((i+1) % 6 == 0) {
                if(active == true) {
                    active = false;
                }
                else {
                    active = true;
                }
            }
            if(active) {
                score1 += nums[i];
            } else {
                score2 += nums[i];
            }
        }
        int diff = score1 - score2;
        return diff;
    }
};