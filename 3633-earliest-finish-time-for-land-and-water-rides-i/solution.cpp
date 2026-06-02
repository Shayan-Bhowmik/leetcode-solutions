class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int landEnd = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                int waterEnd = waterStartTime[j] + waterDuration[j];
                int finish1 = max(landEnd, waterStartTime[j]) + waterDuration[j];
                int finish2 = max(waterEnd, landStartTime[i]) + landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }
        return ans;
    }
};