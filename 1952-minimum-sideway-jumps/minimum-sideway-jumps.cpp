class Solution {
public:
    int n;
    int fun(int lane,vector<int>& obstacles,int i,vector<vector<int>>&dp){
        if(i==n-1)return 0;
        if(dp[i][lane]!=-1)return dp[i][lane];
        int ans=0;
        if(obstacles[i+1]!=lane){
            ans=fun(lane,obstacles,i+1,dp);
        }
        else{
            int mini=INT_MAX;
            for(int it=1;it<=3;it++){
                if(it==lane)continue;
                if(obstacles[i]!=it)mini=min(1+fun(it,obstacles,i,dp),mini);
            }
            ans=mini;
        }
        return dp[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        n=obstacles.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        // dp.resize;
        return fun(2,obstacles,0,dp);
    }
};