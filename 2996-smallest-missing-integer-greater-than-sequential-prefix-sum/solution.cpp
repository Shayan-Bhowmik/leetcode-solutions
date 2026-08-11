class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]==nums[i-1]+1) {
                sum+=nums[i];
            }else{
                break;
            }
        }

        unordered_set<int>dup_nums(nums.begin(), nums.end());
        while(dup_nums.count(sum)) {
            sum++;
        }

        return sum;
    }
};