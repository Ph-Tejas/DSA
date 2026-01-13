class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        dp[n-1][m-1]=1;
        if(grid[n-1][m-1]<0)dp[n-1][m-1]=abs(grid[n-1][m-1])+1;
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                
                if(i==n-1){
                    if(j==m-1)continue;
                    
                    if(dp[i][j+1]-grid[i][j]<0)dp[i][j]=1;
                    else{
                        dp[i][j]=dp[i][j+1]-grid[i][j];
                    }
                }
                else if(j==m-1){
                    if(dp[i+1][j]-grid[i][j]<0)dp[i][j]=1;
                    else{
                        dp[i][j]=dp[i+1][j]-grid[i][j];
                    }
                }
                else{
                    int num1,num2;
                    //first
                    if(dp[i][j+1]-grid[i][j]<0)num1=1;
                    else num1=dp[i][j+1]-grid[i][j];
                    if(dp[i+1][j]-grid[i][j]<0)num2=1;
                    else num2=dp[i+1][j]-grid[i][j];
                    dp[i][j]=min(num1,num2);


                }
                if(dp[i][j]<=0)dp[i][j]=1;
                

            }
        }
        return dp[0][0];






    }
};