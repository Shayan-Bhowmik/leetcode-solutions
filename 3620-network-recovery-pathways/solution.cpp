class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        int high = 0;

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            high = max(high, e[2]);
        }

        auto check = [&](int limit) -> bool {

            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;

            queue<int> q;
            vector<int> deg = indegree;

            for (int i = 0; i < n; i++)
                if (deg[i] == 0)
                    q.push(i);

            while (!q.empty()) {

                int u = q.front();
                q.pop();

                if (dist[u] != LLONG_MAX) {

                    for (auto &[v, w] : graph[u]) {

                        if (w < limit)
                            continue;

                        if (v != n - 1 && !online[v])
                            continue;

                        dist[v] = min(dist[v], dist[u] + (long long)w);
                    }
                }

                for (auto &[v, w] : graph[u]) {
                    deg[v]--;
                    if (deg[v] == 0)
                        q.push(v);
                }
            }

            return dist[n - 1] <= k;
        };

        int low = 0;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};