class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& penalty) {

        priority_queue<
            pair<long long, pair<pair<long long, long long>, long long>>,
            vector<pair<long long, pair<pair<long long, long long>, long long>>>,
            greater<pair<long long, pair<pair<long long, long long>, long long>>>
        > pq;

        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2)));
        vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(2, LLONG_MAX)));

        pq.push({1, {{0, 0}, 1}});

        while (!pq.empty()) {
            long long cost = pq.top().first;
            long long i = pq.top().second.first.first;
            long long j = pq.top().second.first.second;
            long long atp = pq.top().second.second;

            pq.pop();

            if (vis[i][j][atp]) continue;
            vis[i][j][atp] = true;
            if (dist[i][j][atp] <= cost) continue;
            else dist[i][j][atp] = cost;

            if (i == n - 1 && j == m - 1) return cost;

            if (!vis[i][j][!atp] && dist[i][j][!atp] > cost + penalty[i][j]) {
                pq.push({cost + penalty[i][j], {{i, j}, !atp}});
            }

            if (i + 1 < n && (!vis[i + 1][j][!atp]) &&
                dist[i + 1][j][!atp] > cost + ((i + 2) * (j + 1))) {
                if (atp) {
                    pq.push({cost + ((i + 2) * (j + 1)), {{i + 1, j}, !atp}});
                } else {
                    if (dist[i + 1][j][!atp] > cost + ((i + 2) * (j + 1)) + penalty[i][j]) {
                        pq.push({cost + ((i + 2) * (j + 1)) + penalty[i][j], {{i + 1, j}, !atp}});
                    }
                }
            }

            if (j + 1 < m && (!vis[i][j + 1][!atp]) &&
                dist[i][j + 1][!atp] > cost + ((i + 2) * (j + 1))) {
                if (atp) {
                    pq.push({cost + ((i + 1) * (j + 2)), {{i, j + 1}, !atp}});
                } else {
                    if (dist[i][j + 1][!atp] > cost + ((i + 1) * (j + 2)) + penalty[i][j]) {
                        pq.push({cost + ((i + 1) * (j + 2)) + penalty[i][j], {{i, j + 1}, !atp}});
                    }
                }
            }

            if (i - 1 > -1 && (!vis[i - 1][j][!atp]) &&
                dist[i - 1][j][!atp] > cost + ((i + 2) * (j + 1))) {
                if (!atp) {
                    pq.push({cost + ((i) * (j + 1)), {{i - 1, j}, !atp}});
                } else {
                    if (dist[i - 1][j][!atp] > cost + ((i) * (j + 1)) + penalty[i][j]) {
                        pq.push({cost + ((i) * (j + 1)) + penalty[i][j], {{i - 1, j}, !atp}});
                    }
                }
            }

            if (j - 1 > -1 && (!vis[i][j - 1][!atp]) &&
                dist[i][j - 1][!atp] > cost + ((i + 2) * (j + 1))) {
                if (!atp) {
                    pq.push({cost + ((i + 1) * (j)), {{i, j - 1}, !atp}});
                } else {
                    if (dist[i][j - 1][!atp] > cost + ((i + 1) * (j)) + penalty[i][j]) {
                        pq.push({cost + ((i + 1) * (j)) + penalty[i][j], {{i, j - 1}, !atp}});
                    }
                }
            }
        }

        return -1;
    }
};