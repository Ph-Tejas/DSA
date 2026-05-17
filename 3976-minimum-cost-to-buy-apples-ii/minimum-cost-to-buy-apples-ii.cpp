class Solution {
public:
    long long N;
    long long sz;

    vector<vector<vector<long long>>> adj;
    vector<int> ans;

    priority_queue<
        pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<pair<long long, long long>>
    > pq;

    void fun(long long node, vector<int>& prices) {

        vector<bool> vis(N, false);
        vector<long long> ans1(N, 1e18);

        pq.push({0, node});

        int P = prices[node];

        while (!pq.empty()) {

            long long curr = pq.top().first;
            long long nd = pq.top().second;

            pq.pop();

            if (vis[nd]) continue;

            if (curr > P) break;

            ans1[nd] = curr;

            vis[nd] = true;

            for (int i = 0; i < adj[nd].size(); i++) {

                if (vis[adj[nd][i][0]]) continue;

                pq.push({
                    curr + adj[nd][i][1],
                    adj[nd][i][0]
                });
            }
        }

        for (int i = 0; i < N; i++) {
            vis[i] = false;
        }

        while (!pq.empty()) pq.pop();

        pq.push({0, node});

        while (!pq.empty()) {

            long long curr = pq.top().first;

            long long nd = pq.top().second;

            pq.pop();

            if (vis[nd]) continue;

            if (curr > P) break;

            if (ans[node] > curr + ans1[nd] + prices[nd]) {

                ans[node] = curr + ans1[nd] + prices[nd];
            }

            vis[nd] = true;

            for (int i = 0; i < adj[nd].size(); i++) {

                if (vis[adj[nd][i][0]]) continue;

                pq.push({
                    curr + adj[nd][i][2],
                    adj[nd][i][0]
                });
            }
        }

        while (!pq.empty()) pq.pop();
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {

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