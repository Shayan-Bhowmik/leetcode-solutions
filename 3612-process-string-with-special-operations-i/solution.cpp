class Solution {
public:
    string processStr(string s) {
        int n = s.length();

        string result;

        for(int i=0; i<n; i++) {
            
            if(s[i] == '*') {
                if(result.size() == 0) {
                    continue;
                }
                else{
                    result.erase(result.size()-1, 1);
                }
                
            }
            else if(s[i] == '#') {
                result.append(result);
            }
            else if(s[i] == '%') {
                reverse(result.begin(), result.end());
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};