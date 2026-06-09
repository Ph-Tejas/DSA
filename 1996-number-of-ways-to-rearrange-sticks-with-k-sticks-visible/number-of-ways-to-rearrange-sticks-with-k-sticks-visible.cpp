class Solution {
public:
    long long mod=1e9+7;
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        for(int i=0;i<=min(n,k);i++){
            dp[i][i]=1;
        }
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=k;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=0;
        }

        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(dp[i][j]==-1){
                    dp[i][j]=((dp[i-1][j-1]+((((long long)(i-1))*(dp[i-1][j]))%mod))%mod);

                }
            }
        }
        return dp[n][k];
    }
};