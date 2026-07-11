class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    pair<int, int> dfs(int node) {
        vis[node] = true;

        int nodes = 1;
        int degreeSum = adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                auto [n, d] = dfs(nei);
                nodes += n;
                degreeSum += d;
            }
        }

        return {nodes, degreeSum};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                auto [nodes, degreeSum] = dfs(i);

                if (degreeSum >= nodes * (nodes - 1))
                    ans++;
            }
        }

        return ans;
    }
};