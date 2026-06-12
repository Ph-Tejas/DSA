class Solution {
public:
    vector<int>dp;
    int minSteps(int n) {
        if(n==1)return 0;
        dp.resize(n+1);
        for(int i=2;i<=n;i++){
            dp[i]=i;
        }
        for(int i=2;i<=n;i++){
            if(i==n)return dp[n];
            for(int j=i+i,ct=2;j<=n;j+=i,ct++){
                dp[j]=min(dp[i]+ct,dp[j]);
            }

        }
        return 0;
    }
};