class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod=1e9+7;
        if(n==1){
            if(k==0)return 1;
            else return 0;
        }
        if(k==0)return 1;
        vector<vector<long long>>dp(n+1,vector<long long>(1001));
        dp[1][0]=1;
        dp[2][0]=2;
        dp[2][1]=1;
        for(int i=3;i<=n;i++){
            for(int j=1000;j>-1;j--){
                if(j==1000)dp[i][j]=dp[i-1][1000-i+1];
                else if(j==0)dp[i][j]=1+dp[i][1];
                else if(i-1>j){
                    dp[i][j]=(dp[i-1][0]-dp[i-1][j+1]+mod)+dp[i][j+1];
                }
                else{
                    dp[i][j]=(dp[i-1][j-i+1]-dp[i-1][j+1]+mod)+dp[i][j+1];
                }
                dp[i][j]%=mod;
                
            }
        }
        return (k==1000)?(dp[n][k]):(dp[n][k]-dp[n][k+1]+mod)%mod;


        
        
        
    }
};