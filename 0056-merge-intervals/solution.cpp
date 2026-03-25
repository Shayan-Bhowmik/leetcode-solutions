class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int i1 = ans.back()[0];
            int j1 = ans.back()[1];

            int i2 = intervals[i][0];
            int j2 = intervals[i][1];

            if (j1 >= i2) {
                ans.back()[1] = max(j1, j2);
            } 
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};