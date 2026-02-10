class Solution {
public:
    int rec(int it,vector<int>&v,vector<int>&dp){
        if(it>20000)return 0;
        if(dp[it]!=-1)return dp[it];
        if(v[it]==0)return rec(it+1,v,dp);
        return dp[it]=max(rec(it+2,v,dp)+v[it],rec(it+1,v,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>v(20001);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]+=nums[i];
        }
        int it=1;
        vector<int>dp(20001,-1);
        return rec(it,v,dp);
    }
};