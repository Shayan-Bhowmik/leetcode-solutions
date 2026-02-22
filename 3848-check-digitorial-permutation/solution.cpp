class Solution {
public:
    int factorial(int n) {
        int fact = 1;
        for(int i=1; i<=n; i++) {
            fact *= i;
        }
        return fact;
    }
    
    bool isDigitorialPermutation(int n) {
        int Onum = n;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum = sum + factorial(digit);
            n = n / 10;
        }

        string O = to_string(Onum);
        sort(O.begin(), O.end());
        string S = to_string(sum);
        sort(S.begin(), S.end());

        if (O.length() != S.length()) {
            return false;
        }
        else if (O == S) {
            return true;
        }
        else {
            return false;
        }
    }
};