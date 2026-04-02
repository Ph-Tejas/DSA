class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();

        int m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3)));


        for(int i=0;i<n;i++){
            int curr=coins[i][0];
            if(i==0){
                
                if(curr>=0){
                    dp[i][0][2]=curr;
                    dp[i][0][1]=curr;
                    dp[i][0][0]=curr;
                    
                }
                else {
                    dp[i][0][2]=curr;
                    dp[i][0][1]=0;
                    dp[i][0][0]=0;
                }
            }
            else{
                dp[i][0][2]=dp[i-1][0][2]+curr;
                if(curr>=0){
                    dp[i][0][1]=dp[i-1][0][1]+curr;
                    dp[i][0][0]=dp[i-1][0][0]+curr;
                    
                }
                else{
                    dp[i][0][1]=max(dp[i-1][0][1]+curr,dp[i-1][0][2]);
                    dp[i][0][0]=max(dp[i-1][0][0]+curr,dp[i-1][0][1]);
                }
                
            }
        }
        for(int i=1;i<m;i++){
            int curr=coins[0][i];
            
           
            dp[0][i][2]=dp[0][i-1][2]+curr;
            if(curr>=0){
                dp[0][i][1]=dp[0][i-1][1]+curr;
                dp[0][i][0]=dp[0][i-1][0]+curr;
                
            }
            else{
                dp[0][i][1]=max(dp[0][i-1][1]+curr,dp[0][i-1][2]);
                dp[0][i][0]=max(dp[0][i-1][0]+curr,dp[0][i-1][1]);
            }
            
        
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int curr=coins[i][j];
                if(curr<0){
                    dp[i][j][2]=max(dp[i-1][j][2]+curr,dp[i][j-1][2]+curr);
                    dp[i][j][1]=max({dp[i-1][j][1]+curr,dp[i][j-1][1]+curr,dp[i-1][j][2],dp[i][j-1][2]});
                    dp[i][j][0]=max({dp[i-1][j][0]+curr,dp[i][j-1][0]+curr,dp[i-1][j][1],dp[i][j-1][1]});
                }
                else{
                    dp[i][j][2]=max(dp[i-1][j][2]+curr,dp[i][j-1][2]+curr);
                    dp[i][j][1]=max(dp[i-1][j][1]+curr,dp[i][j-1][1]+curr);
                    dp[i][j][0]=max(dp[i-1][j][0]+curr,dp[i][j-1][0]+curr);
                    
                }
            }
        }
        return max({dp[n-1][m-1][0],dp[n-1][m-1][1],dp[n-1][m-1][2]});
        



    }
};