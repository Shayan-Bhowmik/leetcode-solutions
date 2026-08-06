class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> copy_nums(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        int n=nums.size();
        int min=nums[0];
        int max=nums[n-1];

        vector<int> ans;
        for(int i=min; i<=max; i++) {
            if(!copy_nums.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};