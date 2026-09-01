class Solution {
public:
    int n, m, R, bit1, totalVis;
    int lockId[20][20]; 
    int tgt;
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

    vector<int> dist;

    inline int idx(int i, int j, int vis, int k) {
        return ((i * m + j) * totalVis + vis) * (R + 1) + k;
    }

    struct State {
        int i, j, vis, k, ct;
    };

    int minMoves(vector<string>& nums, int k) {
        n = nums.size();
        m = nums[0].size();
        R = k;

        memset(lockId, -1, sizeof(lockId));

        int si = -1, sj = -1;
        bit1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 'L') {
                    lockId[i][j] = bit1;
                    bit1++;
                }
                if (nums[i][j] == 'S') {
                    si = i; sj = j;
                }
            }
        }

        tgt = (1 << bit1) - 1;
        totalVis = 1 << bit1;

        dist.assign((size_t)n * m * totalVis * (R + 1), -1);

        queue<State> q;
        q.push({si, sj, 0, k, 0});
        dist[idx(si, sj, 0, k)] = 0;

        int limit = n * m;

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            if (cur.vis == tgt) return cur.ct;
            if (cur.ct >= limit) continue;
            if (cur.k - 1 < 0) continue;

            for (int d = 0; d < 4; d++) {
                int ni = cur.i + dir[d][0];
                int nj = cur.j + dir[d][1];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (nums[ni][nj] == 'X') continue;

                int newVis = cur.vis;
                int newK = cur.k - 1;

                if (nums[ni][nj] == 'L') {
                    newVis |= (1 << lockId[ni][nj]);
                }
                if (nums[ni][nj] == 'R') {
                    newK = R;
                }

                int id = idx(ni, nj, newVis, newK);
                if (dist[id] == -1) {
                    dist[id] = cur.ct + 1;
                    q.push({ni, nj, newVis, newK, cur.ct + 1});
                }
            }
        }

        return -1;
    }
};