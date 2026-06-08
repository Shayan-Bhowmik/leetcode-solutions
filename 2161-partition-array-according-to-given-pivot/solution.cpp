class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(nums[i] < pivot) {
                v1.push_back(nums[i]);
            }
            else if(nums[i] == pivot) {
                v3.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }

        v1.insert(v1.end(), v3.begin(), v3.end());
        v1.insert(v1.end(), v2.begin(), v2.end());

        return v1;
    }
};