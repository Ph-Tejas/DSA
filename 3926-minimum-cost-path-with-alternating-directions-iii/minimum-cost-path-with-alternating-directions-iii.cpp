class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& penalty) {

        priority_queue<vector<long long>,
                       vector<vector<long long>>,
                       greater<vector<long long>>> pq;

        vector<vector<vector<long long>>> dist(
            n, vector<vector<long long>>(m, vector<long long>(2, LLONG_MAX)));

        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            long long cost = cur[0];
            int i = cur[1];
            int j = cur[2];
            int atp = cur[3];

            if (cost != dist[i][j][atp]) continue;

            if (i == n - 1 && j == m - 1)
                return cost;

            // Stay
            long long newCost = cost + penalty[i][j];
            if (newCost < dist[i][j][!atp]) {
                dist[i][j][!atp] = newCost;
                pq.push({newCost, i, j, !atp});
            }

            // Down
            if (i + 1 < n) {
                if (atp) {
                    newCost = cost + (long long)(i + 2) * (j + 1);
                } else {
                    newCost = cost + penalty[i][j] +
                              (long long)(i + 2) * (j + 1);
                }

                if (newCost < dist[i + 1][j][!atp]) {
                    dist[i + 1][j][!atp] = newCost;
                    pq.push({newCost, i + 1, j, !atp});
                }
            }

            // Right
            if (j + 1 < m) {
                if (atp) {
                    newCost = cost + (long long)(i + 1) * (j + 2);
                } else {
                    newCost = cost + penalty[i][j] +
                              (long long)(i + 1) * (j + 2);
                }

                if (newCost < dist[i][j + 1][!atp]) {
                    dist[i][j + 1][!atp] = newCost;
                    pq.push({newCost, i, j + 1, !atp});
                }
            }

            // Up
            if (i - 1 >= 0) {
                if (!atp) {
                    newCost = cost + (long long)i * (j + 1);
                } else {
                    newCost = cost + penalty[i][j] +
                              (long long)i * (j + 1);
                }

                if (newCost < dist[i - 1][j][!atp]) {
                    dist[i - 1][j][!atp] = newCost;
                    pq.push({newCost, i - 1, j, !atp});
                }
            }

            // Left
            if (j - 1 >= 0) {
                if (!atp) {
                    newCost = cost + (long long)(i + 1) * j;
                } else {
                    newCost = cost + penalty[i][j] +
                              (long long)(i + 1) * j;
                }

                if (newCost < dist[i][j - 1][!atp]) {
                    dist[i][j - 1][!atp] = newCost;
                    pq.push({newCost, i, j - 1, !atp});
                }
            }
        }

        return -1;
    }
};