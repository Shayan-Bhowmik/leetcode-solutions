class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        
        int total_sum = 0;
            for(int i=n-1; i>=0; i=i-3) {
                total_sum = total_sum + cost[i];
                if(i-1 >= 0) {
                    total_sum = total_sum + cost[i-1];
                }
            }
            return total_sum;
    }
};