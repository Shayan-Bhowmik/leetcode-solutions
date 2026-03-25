class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        int j=0, maxLen = 0;

        for (int i=0;  i<n; i++) {
            if (m.find(s[i]) != m.end()) {
                j = max(j, m[s[i]] + 1);
            }

            m[s[i]]=i;
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};