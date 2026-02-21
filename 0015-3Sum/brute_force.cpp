class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int first;
        int second;
        int third;

        set<vector<int>> s;
        
        for(int i=0; i<n; i++) {
            first = nums[i];
            for(int j=i+1; j<n; j++) {
                second = nums[j];
                for(int k=j+1; k<n; k++) {
                    third = nums[k];
                    if(first + second + third == 0) {
                        vector<int> triplet = {first, second, third};
                        sort(triplet.begin(), triplet.end());

                        if(s.find(triplet) == s.end()) {
                            s.insert(triplet);
                            ans.push_back(triplet);
                        }
                    } 
                }
            }
        }
        return ans;
    }
};