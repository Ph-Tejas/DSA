class Solution {
public:
    int N;
    int fun(int ind,int to_take,vector<vector<int>>&dp){
        if(to_take==0)return 1;
        if(dp[ind][to_take]!=-1)return dp[ind][to_take];
        int ans=0;
        for(int i=1;i<=N;i++){

            if((((to_take>>i)&1)==1)&&(ind%i==0 || i%ind==0)){
                ans+=fun(ind+1,(to_take)&(~(1<<i)),dp);
            }
        }
        return dp[ind][to_take]=ans;
    }
    int countArrangement(int n) {
        N=n;
        vector<vector<int>>dp(n+1,vector<int>((1<<(n+1)),-1));
        return fun(1,(1<<(n+1))-2,dp);


    }
};