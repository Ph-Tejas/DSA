class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> pow2;
    int LOG;

    void dfs(int node, int par) {
        up[node][0] = par;

        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] == -1)
                up[node][j] = -1;
            else
                up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nxt : adj[node]) {
            if (nxt == par) continue;
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int kthAncestor(int node, int k) {
        for (int j = 0; j < LOG && node != -1; j++) {
            if (k & (1 << j))
                node = up[node][j];
        }
        return node;
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        a = kthAncestor(a, depth[a] - depth[b]);

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        int maxDepth = n + 5;

        pow2.assign(maxDepth, 1);
        for (int i = 1; i < maxDepth; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int L = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[L];

            ans.push_back(pow2[dist - 1]);
        }

        return ans;
    }
};