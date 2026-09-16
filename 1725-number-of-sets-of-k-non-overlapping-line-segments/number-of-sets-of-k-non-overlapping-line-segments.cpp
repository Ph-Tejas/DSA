class Solution {
public:
    int mod=1e9+7;
    
    int numberOfSets(int n, int k) {
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(k+1,vector<long long>(2)));
    
        dp[n-1][1][1]=1;
        for(int i=0;i<n;i++){
            dp[i][0][0]=1;
            dp[i][0][0]=1;
            
        }

        
        for(int i=n-2;i>-1;i--){
            for(int j=1;j<=k;j++){
                for(int l=0;l<2;l++){
                    if(l==0){
                        dp[i][j][l]=(dp[i+1][j][0]+dp[i+1][j][1])%mod;

                    }
                    else{
                        dp[i][j][l]=(((dp[i+1][j-1][0]+dp[i+1][j-1][1])%mod)+dp[i+1][j][1])%mod;
                    }
                }

            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=k;j++){
        //         cout<<dp[i][j][0]<<","<<dp[i][j][1]<<"             ";
                
                
        //     }
        //     cout<<endl;
        // }
        return (dp[0][k][0])%mod;
        

    }
};