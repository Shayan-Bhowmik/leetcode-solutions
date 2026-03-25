class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.size();
        vector<bool> ans(n + 1, false);
        
        ans[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                
                string word = s.substr(j, i - j);
                
                if (ans[j] && dict.find(word) != dict.end()) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[n];
    }
};