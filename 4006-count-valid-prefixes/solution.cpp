class Solution {
public:
    int countValidPrefixes(string s) {
        int count_zero=0;
        int count_one=0;
        int ans=0;
        for(char c: s) {
            if(c=='0') {
                count_zero++;
            }
            else{
                count_one++;
            }

            if(abs(count_zero - count_one) <= 1) {
                ans++;
            }
        }
        return ans;
    }
};