class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        int n = nums.size();
        for(int i=0; i<n; i++) {
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            
            m[first] = i;
        }
        return ans;
    }
};