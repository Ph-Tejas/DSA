class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<vector<bool>> dont_come;

    int fun(int vis, int node, vector<vector<int>>& graph) {
        if (vis == ((1 << n) - 1)) return 0;

        // FIX 1: We don't just check -1. 
        // We only return if we've found a result that is already very good.
        // In DFS for shortest paths, we often have to re-evaluate nodes.
        if (dp[node][vis] != -1 && dp[node][vis] < 100) { // 100 is safe since max steps < n * 2^n
             return dp[node][vis];
        }

        dont_come[node][vis] = true;
        int mini = 1e6; 
        
        for (int i = 0; i < graph[node].size(); i++) {
            int curr = graph[node][i];
            int new_vis = vis | (1 << curr);
            
            if (dont_come[curr][new_vis]) continue;
            
            mini = min(mini, 1 + fun(new_vis, curr, graph));
        }
        
        dont_come[node][vis] = false;
        return dp[node][vis] = mini;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        int final_mini = 1e6;

        // FIX 2: To guarantee the shortest path in DFS, we must ensure 
        // we don't let "stale" DP values from one start node ruin another.
        for (int i = 0; i < n; i++) {
            dp.assign(n, vector<int>((1 << n), -1));
            dont_come.assign(n, vector<bool>((1 << n), false));
            final_mini = min(final_mini, fun((1 << i), i, graph));
        }
        
        return final_mini;
    }
};