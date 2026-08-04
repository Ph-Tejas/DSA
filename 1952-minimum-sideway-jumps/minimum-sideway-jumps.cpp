class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int fun(int lane,vector<int>& obstacles,int i){
        if(i==n-1)return 0;
        if(dp[i][lane]!=-1)return dp[i][lane];
        int ans=0;
        if(obstacles[i+1]!=lane){
            ans=fun(lane,obstacles,i+1);
        }
        else{
            int mini=INT_MAX;
            for(int it=1;it<=3;it++){
                if(it==lane)continue;
                if(obstacles[i]!=it)mini=min(1+fun(it,obstacles,i),mini);
            }
            ans=mini;
        }
        return dp[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        n=obstacles.size();
        dp.resize(n,vector<int>(4,-1));
        return fun(2,obstacles,0);
    }
};