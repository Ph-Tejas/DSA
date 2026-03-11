class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int target) {
        
        const int INF = 1e9;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(target+1, vector<int>(m+1, INF)));

        // first house
        if(houses[0] == 0){
            for(int c=1;c<=m;c++)
                dp[0][1][c] = cost[0][c-1];
        }
        else{
            dp[0][1][houses[0]] = 0;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                for(int c=1;c<=m;c++){

                    if(houses[i] != 0 && houses[i] != c) continue;

                    int paintCost = (houses[i]==0 ? cost[i][c-1] : 0);

                    for(int pc=1;pc<=m;pc++){

                        if(pc == c)
                            dp[i][j][c] = min(dp[i][j][c], dp[i-1][j][pc] + paintCost);
                        else if(j>1)
                            dp[i][j][c] = min(dp[i][j][c], dp[i-1][j-1][pc] + paintCost);
                    }
                }
            }
        }

        int ans = INF;

        for(int c=1;c<=m;c++)
            ans = min(ans, dp[n-1][target][c]);

        return ans >= INF ? -1 : ans;
    }
};