class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>>dp;
    vector<vector<long long>>powy;
    int N,M,K;
    long long fun(int i,int j,int k){
        if(k==0){
            return powy[j][N-i];
        }
        if(N-i<k){
            return 0;
        }
        if(M-j<k){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        long long ans=0;

        for(int it=1;it<=M;it++){
            if(it<=j){
                ans+=fun(i+1,j,k);
                ans%=mod;
            }
            else{
                ans+=fun(i+1,it,k-1);
                ans%=mod;

            }
        }
        return dp[i][j][k]=ans;







    }
    int numOfArrays(int n, int m, int k) {
        N=n,M=m;K=k;
        powy.resize(M+1,vector<long long>(N+1,1));
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                powy[i][j]=powy[i][j-1]*i;
                powy[i][j]%=mod;
            }
        }

        dp.resize(n,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        long long ans=0;
        for(int j=1;j<=m;j++){
            ans+=fun(1,j,k-1);
            ans%=mod;
        }
        return ans;






    }
};