class Solution {
public:
    char processStr(string s, long long k) {

        long long len = 0;

        for(char c : s) {

            if(c == '*') {
                if(len > 0) len--;
            }
            else if(c == '#') {
                len *= 2;
            }
            else if(c == '%') {
                continue;
            }
            else {
                len++;
            }
        }

        if(k >= len)
            return '.';

        for(int i = s.size()-1; i >= 0; i--) {

            char c = s[i];
            
            if(c == '#') {

                long long oldLen = len / 2;

                if(k >= oldLen)
                    k -= oldLen;
                len = oldLen;
            }

            else if(c == '%') {
                k = len - 1 - k;
            }

            else if(c == '*') {

                len++;
                if(k == len - 1)
                    return '.';
            }

            else {

                len--;
                if(k == len)
                    return c;
            }
        }
        return '.';
    }
};