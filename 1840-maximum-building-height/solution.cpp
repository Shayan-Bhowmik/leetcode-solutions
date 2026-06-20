class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                (restrictions[i][0] - restrictions[i - 1][0])
            );
        }
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        int ans = 0;

        for (int i = 0; i < m - 1; i++) {

            long long p1 = restrictions[i][0];
            long long h1 = restrictions[i][1];

            long long p2 = restrictions[i + 1][0];
            long long h2 = restrictions[i + 1][1];

            long long dist = p2 - p1;
            long long peak = (dist + h1 + h2) / 2;

            ans = max(ans, (int)peak);
        }

        ans = max(
            ans,
            restrictions.back()[1] +
            (n - restrictions.back()[0])
        );


        return ans;
    }
};