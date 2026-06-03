class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ear_land_time = INT_MAX;
        int ear_water_time = INT_MAX;
        int land_wait_water = INT_MAX;
        int water_wait_land = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0; i<n; i++) {
            ear_land_time = min(ear_land_time, landStartTime[i] + landDuration[i]);
        }

        for(int j=0; j<m; j++) {
            ear_water_time = min(ear_water_time, waterStartTime[j] + waterDuration[j]);
            land_wait_water = min(land_wait_water, max(waterStartTime[j], ear_land_time) + waterDuration[j]);
        }

        for(int k=0; k<n; k++) {
            water_wait_land = min(water_wait_land, max(landStartTime[k], ear_water_time) + landDuration[k]);
        }

        return min(land_wait_water, water_wait_land);
    }
};