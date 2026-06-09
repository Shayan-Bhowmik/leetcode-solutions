class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = 0;
        int minElement = INT_MAX;

        for(int i=0; i<n; i++) {
            maxElement = max(maxElement, nums[i]);
        }

        for(int i=0; i<n; i++) {
            minElement = min(minElement, nums[i]);
        }

        long long subElement = maxElement - minElement;

        return subElement * k;
    }
};