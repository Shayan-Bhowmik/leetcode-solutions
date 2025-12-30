class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();

        for(int i=0; i<size; i++) {
            for(int j=0; j<size-i-1; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        for(int i=0; i<size; i++) {
            if(i != nums[i]) {
                return i;
            }
        }
        return size;
    }
};