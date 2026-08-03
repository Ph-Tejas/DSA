class Solution {
public:
    int dp[201][201];
    
    int fun(int i,int j){
        int mini=INT_MAX;
        if(i==j)return 0;
        if(j-i==1)return i;
        if(dp[i][j]!=-1)return dp[i][j];

        for(int it=i+1;it<j;it++){
            mini=min(mini,it+max(fun(i,it-1),fun(it+1,j)));
        }
        return dp[i][j]=mini;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(1,n);
    }
};