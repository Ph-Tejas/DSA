class Solution {
public:
    vector<int>dp;
    bool fun(int n){
        if(n==0)return false;
        if(dp[n]!=-1)return dp[n];
        int ans=false;

        for(int i=1;i*i<=n;i++){
            ans=(ans||(!fun(n-(i*i))));
        }
        return dp[n]=ans;
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return fun(n);
    }
};