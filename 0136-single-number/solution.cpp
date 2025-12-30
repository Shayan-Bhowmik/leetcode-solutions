class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;

        for(int val: nums) {
            value = value ^ val;
        }
        return value;
    }
};