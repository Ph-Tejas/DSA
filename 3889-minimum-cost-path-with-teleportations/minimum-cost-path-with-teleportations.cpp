class Solution {
public:
    int findp(vector<int>& p, int x) {
        if (p[x] == x) return x;
        return p[x] = findp(p, p[x]);
    }

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        if (k && grid[0][0] >= grid[n - 1][m - 1]) {
    return 0;
}


        vector<vector<int>> vis(N, vector<int>(k + 1, 0));

        vector<pair<int,int>> cells(N);
        for (int i = 0; i < N; i++)
            cells[i] = {grid[i / m][i % m], i};
        sort(cells.begin(), cells.end());

        vector<vector<int>> nextPos(k);
        for (int t = 0; t < k; t++) {
            nextPos[t].resize(N + 1);
            for (int i = 0; i <= N; i++) nextPos[t][i] = i;
        }

        priority_queue<
            array<int,3>,
            vector<array<int,3>>,
            greater<array<int,3>>
        > pq;

        pq.push({0, N - 1, k});

        while (!pq.empty()) {
            auto [cost, box, tele] = pq.top(); pq.pop();
            if (vis[box][tele]) continue;
            vis[box][tele] = 1;

            if (box == 0) return cost;

            int x = box / m, y = box % m;

            if (x > 0 && !vis[box - m][tele])
                pq.push({cost + grid[x][y], box - m, tele});

            if (y > 0 && !vis[box - 1][tele])
                pq.push({cost + grid[x][y], box - 1, tele});

            if (tele > 0) {
                int currVal = grid[x][y];
                int pos = lower_bound(
                    cells.begin(), cells.end(),
                    make_pair(currVal, -1)
                ) - cells.begin();

                auto &p = nextPos[tele - 1];
                for (int i = findp(p, pos); i < N; i = findp(p, i)) {
                    p[i] = findp(p, i + 1);
                    int nxt = cells[i].second;
                    if (!vis[nxt][tele - 1])
                        pq.push({cost, nxt, tele - 1});
                }
            }
        }
        return -1;
    }
};
