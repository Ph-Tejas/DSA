class Solution {
public:
    long long N;
    long long sz;

    vector<vector<vector<long long>>> adj;
    vector<int> ans;

    priority_queue<
        vector<long long>,
        vector<vector<long long>>,
        greater<vector<long long>>
    > pq;

    void fun(long long node, vector<int>& prices) {

        vector<bool> vis(N, false);
        vector<long long> ans1(N, LLONG_MAX);

        pq.push({0, node});
        ans1[node] = 0;

        // First Dijkstra
        while (!pq.empty()) {

            long long curr = pq.top()[0];
            long long nd = pq.top()[1];
            pq.pop();

            if (vis[nd]) continue;
            vis[nd] = true;

            if (curr > prices[node]) break;

            for (int i = 0; i < adj[nd].size(); i++) {

                long long nxt = adj[nd][i][0];
                long long wt = adj[nd][i][1];

                if (vis[nxt]) continue;

                long long newDist = curr + wt;

                if (newDist < ans1[nxt]) {

                    ans1[nxt] = newDist;

                    pq.push({
                        newDist,
                        nxt
                    });
                }
            }
        }

        for (int i = 0; i < N; i++) {
            vis[i] = false;
        }

        while (!pq.empty()) pq.pop();

        vector<long long> dist2(N, LLONG_MAX);

        pq.push({0, node});
        dist2[node] = 0;

        // Second Dijkstra
        while (!pq.empty()) {

            long long curr = pq.top()[0];
            long long nd = pq.top()[1];
            pq.pop();

            if (vis[nd]) continue;
            vis[nd] = true;

            if (curr > prices[node]) break;

            if (ans1[nd] != LLONG_MAX) {

                ans[node] = min(
                    (long long)ans[node],
                    curr + ans1[nd] + prices[nd]
                );
            }

            for (int i = 0; i < adj[nd].size(); i++) {

                long long nxt = adj[nd][i][0];
                long long wt = adj[nd][i][2];

                if (vis[nxt]) continue;

                long long newDist = curr + wt;

                if (newDist < dist2[nxt]) {

                    dist2[nxt] = newDist;

                    pq.push({
                        newDist,
                        nxt
                    });
                }
            }
        }

        while (!pq.empty()) pq.pop();
    }

    vector<int> minCost(
        int n,
        vector<int>& prices,
        vector<vector<int>>& roads
    ) {

        N = n;
        sz = roads.size();

        adj.resize(n);

        ans = prices;

        for (int i = 0; i < sz; i++) {

            adj[roads[i][0]].push_back({
                roads[i][1],
                roads[i][2],
                (long long)roads[i][2] * roads[i][3]
            });

            adj[roads[i][1]].push_back({
                roads[i][0],
                roads[i][2],
                (long long)roads[i][2] * roads[i][3]
            });
        }

        for (int i = 0; i < n; i++) {
            fun(i, prices);
        }

        return ans;
    }
};