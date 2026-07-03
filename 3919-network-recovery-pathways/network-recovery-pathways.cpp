class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        int lo = 0, hi = 1e9;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            vector<long long> dist(n, LLONG_MAX);
            priority_queue<
                pair<long long,int>,
                vector<pair<long long,int>>,
                greater<pair<long long,int>>
            > pq;

            dist[0] = 0;
            pq.push({0, 0});

            bool ok = false;

            while (!pq.empty()) {
                auto [cost, node] = pq.top();
                pq.pop();

                if (cost != dist[node])
                    continue;

                if (node == n - 1) {
                    ok = true;
                    break;
                }

                for (auto &[next, wt] : adj[node]) {
                    if (wt < mid) continue;
                    if (!online[next]) continue;

                    long long newCost = cost + wt;
                    if (newCost > k) continue;

                    if (newCost < dist[next]) {
                        dist[next] = newCost;
                        pq.push({newCost, next});
                    }
                }
            }

            if (ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};