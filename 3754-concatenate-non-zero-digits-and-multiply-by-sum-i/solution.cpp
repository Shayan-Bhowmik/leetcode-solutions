class Solution {
public:
    long long sumAndMultiply(int n) {
        string num_string = to_string(n);

        long long sum = 0;
        string str = "";

        for(int i=0; i<num_string.size(); i++) {
            if(num_string[i] != '0') {
                sum += (num_string[i] - '0'); 
                str.push_back(num_string[i]); 
            }
            else{
                continue;
            }
        }

        if(str.empty()) {
            return 0;
        }

        long long number = stoll(str);
        return number * sum;
    }
};