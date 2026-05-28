class Solution {
public:
long long mod=1e9+7;
    int countVowelPermutation(int n) {
        // map<char,int>mp;
        // mp['a']=0;
        // mp['e']=1;
        // mp['i']=2;
        // mp['o']=3;
        // mp['u']=4;
        vector<vector<long long>>dp(n,vector<long long>(5));
        for(int i=0;i<5;i++){
            dp[n-1][i]=1;

        }
        if(n==1)return 5;
        //dp[i][j]%=mod;
        long long ans=0;
        for(int i=n-2;i>-1;i--){
            for(int j=0;j<5;j++){
                if(j==0){
                    dp[i][j]+=dp[i+1][1];
                    dp[i][j]%=mod;
                }
                else if(j==1){
                    dp[i][j]+=dp[i+1][0];
                    dp[i][j]%=mod;
                    dp[i][j]+=dp[i+1][2];
                    dp[i][j]%=mod;
                }
                else if(j==2){
                    dp[i][j]+=dp[i+1][0];
                    dp[i][j]%=mod;
                    dp[i][j]+=dp[i+1][1];
                    dp[i][j]%=mod;
                    dp[i][j]+=dp[i+1][3];
                    dp[i][j]%=mod;
                    dp[i][j]+=dp[i+1][4];
                    dp[i][j]%=mod;
                }
                else if(j==3){
                    dp[i][j]+=dp[i+1][2];
                    dp[i][j]%=mod;
                    dp[i][j]+=dp[i+1][4];
                    dp[i][j]%=mod;
                }
                else if(j==4){
                    dp[i][j]+=dp[i+1][0];
                    dp[i][j]%=mod;
                }
                

                
            }
            if(i==0){
                for(int j=0;j<5;j++){
                    ans+=dp[i][j];
                    ans%=mod;
                }
            }
        }
        return ans;
        

        
    }
};