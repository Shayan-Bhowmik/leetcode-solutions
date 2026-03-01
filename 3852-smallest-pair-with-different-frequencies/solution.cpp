class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        if (nums.size() < 2) {
            return {-1, -1};
        }

        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        vector<int> v;
        for (auto p : m) {
            v.push_back(p.first);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (m[v[i]] != m[v[j]]) {
                    return {v[i], v[j]};
                }
            }
        }

        return {-1, -1};
    }
};