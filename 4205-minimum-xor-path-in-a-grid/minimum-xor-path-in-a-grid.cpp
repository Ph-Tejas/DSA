class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,*max_element(grid[i].begin(),grid[i].end()));
        }
        int ct=0;
        while(maxi>0){
            ct++;
            maxi/=2;
        }
        int limit=(1<<ct);


        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(limit)));
        dp[0][0][grid[0][0]]=true;
        for(int i=1;i<n;i++){
            for(int k=0;k<(limit);k++){
                if(dp[i-1][0][k]){
                    dp[i][0][(k^grid[i][0])]=true;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int k=0;k<(limit);k++){
                if(dp[0][i-1][k]){
                    dp[0][i][(k^grid[0][i])]=true;
                }
            }

        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                for(int k=0;k<(limit);k++){
                    if(dp[i][j-1][k]){
                        dp[i][j][(k^grid[i][j])]=true;
                    }
                }
                for(int k=0;k<(limit);k++){
                    if(dp[i-1][j][k]){
                        dp[i][j][(k^grid[i][j])]=true;
                    }
                }
            }
        }
        for(int i=0;i<limit;i++){
            if(dp[n-1][m-1][i]){
                return i;
            }
        }
        return -1;






    }
};