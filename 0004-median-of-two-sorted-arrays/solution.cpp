class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for(int i: nums1) {
            ans.push_back(i);
        }
        for(int j: nums2) {
            ans.push_back(j);
        }

        sort(ans.begin(), ans.end());
        int n = ans.size();
        if(n % 2 == 0) {
            double a = ans[n/2 - 1];
            double b = ans[n/2];
            return (a + b) / 2.0;
        }
        else {
            return ans[n/2];
        }
    }
};