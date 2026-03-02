class Solution {
public:
    void printSubset(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if(i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        printSubset(nums, ans, i+1, allSubsets);

        ans.pop_back();
        int index = i+1;
        while(index < nums.size() && nums[index] == nums[index-1]) {
            index++;
        }
        printSubset(nums, ans, index, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        printSubset(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};