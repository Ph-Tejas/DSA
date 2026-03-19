class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod=1e9+7;
        if(n==1){
            if(k==0)return 1;
            else return 0;
        }
        if(k==0)return 1;
        vector<vector<long long>>dp(n+1,vector<long long>(k+1));
        dp[1][0]=1;
        dp[2][0]=2;
        dp[2][1]=1;
        for(int i=3;i<=n;i++){
            for(int j=k;j>-1;j--){
                if(j==k){
                    if(i-1>j){
                        dp[i][j]=(dp[i-1][0]);
                    }
                    else dp[i][j]=dp[i-1][k-i+1];
                }
                else if(i-1>j){
                    dp[i][j]=(dp[i-1][0]-dp[i-1][j+1]+mod)+dp[i][j+1];
                }
                else if(j==0)dp[i][j]=1+dp[i][1];
                else{
                    dp[i][j]=(dp[i-1][j-i+1]-dp[i-1][j+1]+mod)+dp[i][j+1];
                }
                dp[i][j]%=mod;
                
            }
        }
        return (dp[n][k]);


        
        
        
    }
};