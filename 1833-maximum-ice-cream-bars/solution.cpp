class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(), costs.end());
        vector<long long> count(m+1, 0);

        int n = costs.size();

        for(int i=0; i<n; i++) {
            count[costs[i]]++;
        }

        int curr_coins = coins;
        
        int total = 0;
        
        for(int j=0; j<=m; j++) {
            long long curr_cost = 0;
            curr_cost += (count[j]*j);

            if(curr_coins >= curr_cost) {
                curr_coins -= curr_cost;
                total += count[j];
            }
            else{
                total += curr_coins/j;
                return total;
            }
        }
        return total;
    }
};