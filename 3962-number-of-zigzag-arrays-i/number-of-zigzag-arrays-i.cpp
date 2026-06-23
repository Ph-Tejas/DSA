class Solution {
public:
    int mod=1e9+7;
    long long dp[2010][2010][2];
    
    int zigZagArrays(int n, int l, int r) {
        
        for(int i=r;i>=l;i--){
            dp[n-1][i][0]=(dp[n-1][i+1][0]+1)%mod;
        }

        for(int i=l;i<=r;i++){
            dp[n-1][i][1]=(dp[n-1][i-1][1]+1)%mod;
        }

        for(int i=n-2;i>-1;i--){
            for(int j=l;j<=r;j++){
                dp[i][j][1]=(dp[i][j-1][1]+dp[i+1][j+1][0])%mod;
            }
            for(int j=r;j>=l;j--){
                dp[i][j][0]=(dp[i][j+1][0]+dp[i+1][j-1][1])%mod;
            }
        }
        return (dp[0][l][0]+dp[0][r][1])%mod;







    }
};