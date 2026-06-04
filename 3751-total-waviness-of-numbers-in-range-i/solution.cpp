class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;

        for(int i=num1; i<=num2; i++) {
            string str = to_string(i);

            int n = str.size();

            if(n < 3) {
                continue;
            }

            for(int i=1; i<n-1; i++) {
                if((str[i] > str[i-1] && str[i] > str[i+1]) || (str[i] < str[i-1] && str[i] < str[i+1])) {
                    waviness++;
                }
            }
        }
        return waviness;
    }
};