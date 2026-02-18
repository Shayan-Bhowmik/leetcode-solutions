class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int a;
        int b;

        int actualSum=0;
        int expectedSum=0;

        unordered_set<int> s;
        int n = grid.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                actualSum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        expectedSum = (n*n)*((n*n) + 1) / 2;
        b = expectedSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};