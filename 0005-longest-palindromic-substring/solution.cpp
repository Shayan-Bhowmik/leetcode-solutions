class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) {
            return s;
        }

        string result = "";
        for(int i=0; i<n; i++) {
            int start = i;
            int end = i;

            while(start >= 0 && end < n && s[start] == s[end]) {
                start--;
                end++;
            }
            string temp = s.substr(start+1, end-start-1);
            if(temp.size() > result.size()) {
                result = temp;
            }

            start = i;
            end = i+1;
            while(start >= 0 && end < n && s[start] == s[end]) {
                start--;
                end++;
            }
            temp = s.substr(start+1, end-start-1);
            if(temp.size() > result.size()) {
                result = temp;
            }
        }
        return result;
    }
};