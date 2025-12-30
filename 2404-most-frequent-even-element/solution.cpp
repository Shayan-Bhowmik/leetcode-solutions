class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int currFreq = 0;
        int maxFreq = 0;
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (i == 0 || nums[i] != nums[i - 1]) {
                currFreq = 1;
            } else {
                currFreq++;
            }

            if (nums[i] % 2 == 0) {
                if (currFreq > maxFreq) {
                    maxFreq = currFreq;
                    ans = nums[i];
                }
            }
        }

        return ans;
    }
};