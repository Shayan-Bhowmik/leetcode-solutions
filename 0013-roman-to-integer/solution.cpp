class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int x = 0;
        int y = 0;

        vector<char> sym = {'I','V','X','L','C','D','M'};
        vector<int> val = {1,5,10,50,100,500,1000};

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<7; j++) {
                if(s[i] == sym[j]) {
                    if(val[j] < y) {
                        y = y-x;
                        x = x-val[j];
                        y=y+x;
                    }
                    else{
                        x=x+val[j];
                        y=val[j];
                    }
                }
            }
        }
        return x;
    }
};