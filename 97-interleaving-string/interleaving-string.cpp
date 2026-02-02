class Solution {
public:
    int n,m,k;
    int fun(string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp,int i,int j,int t){
        if(dp[i][j][t]!=-1)return dp[i][j][t];
        int ans;
        if(t==k&&i==n&&j==m)ans=1;

        else if(i==n){
            if(s2[j]==s3[t])ans= fun(s1,s2,s3,dp,i,j+1,t+1);
            else ans=0;
        }
        else if(j==m){
            if(s1[i]==s3[t])ans=fun(s1,s2,s3,dp,i+1,j,t+1);
            else ans=0;
        }
        else{
            int a=0,b=0;
            if(s1[i]==s3[t])a=fun(s1,s2,s3,dp,i+1,j,t+1);
            if(s2[j]==s3[t])b=fun(s1,s2,s3,dp,i,j+1,t+1);
            ans=(a|b);
        }
        return dp[i][j][t]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        k=s3.size();
        if(k!=n+m)return false;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        int ans=fun(s1,s2,s3,dp,0,0,0);
        if(ans==1)return true;
        return false;







    }
};