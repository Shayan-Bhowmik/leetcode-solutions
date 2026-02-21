class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqueTriplet;

        for(int i=0; i<n; i++) {
            int target = -nums[i];
            set<int> s;
            for(int j=i+1; j<n; j++) {
                int third = target - nums[j];

                if(s.find(third) != s.end()) {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());

                    uniqueTriplet.insert(triplet);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());
        return ans;
    }
};