class Solution {
public:
    bool checkDivisibility(int n) {
        int use_n = n;
        int digit;
        int sum=0;
        long long prod=1;
        while(use_n > 0) {
            digit = use_n%10;
            sum += digit;
            prod *= digit;
            use_n = use_n / 10;
        }

        int ans=sum+prod;
        if(n % ans == 0) {
            return true;
        }else{
            return false;
        }

    }
};