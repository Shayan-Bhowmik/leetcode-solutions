class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans="";
        sort(strs.begin(), strs.end());
        string start = strs[0];
        string end = strs[n-1];

        for(int i=0; i<min(start.size(), end.size()); i++) {
            if(start[i] != end[i]) {
                return ans;
            }
            ans = ans + start[i];
        }
        return ans;
    }
};