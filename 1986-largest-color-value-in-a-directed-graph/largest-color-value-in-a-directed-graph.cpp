class Solution {
public:
    int n;
    bool cycle = false;

    vector<vector<int>> dp;
    vector<vector<int>> adj;

    // 0 = unvisited
    // 1 = processing
    // 2 = finished
    vector<int> state;

    vector<int>& dfs(int node, string &colors) {
        if(state[node] == 1) {
            cycle = true;
            return dp[node];
        }

        if(state[node] == 2) {
            return dp[node];
        }

        state[node] = 1;

        for(int v : adj[node]) {
            vector<int>& child = dfs(v, colors);

            for(int c = 0; c < 26; c++) {
                dp[node][c] = max(dp[node][c], child[c]);
            }
        }

        dp[node][colors[node] - 'a']++;

        state[node] = 2;

        return dp[node];
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();

        adj.assign(n, {});
        dp.assign(n, vector<int>(26, 0));
        state.assign(n, 0);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(state[i] == 0) {
                dfs(i, colors);
            }
        }

        if(cycle) return -1;

        for(int i = 0; i < n; i++) {
            for(int c = 0; c < 26; c++) {
                ans = max(ans, dp[i][c]);
            }
        }

        return ans;
    }
};