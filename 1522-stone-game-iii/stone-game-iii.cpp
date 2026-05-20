class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int fun(int guy,int ind,vector<int>& nums){
        if(ind==n)return 0;
        if(dp[guy][ind]!=-1)return dp[guy][ind];
        int mul=1;
        if(guy==1)mul*=-1;
        int curr=0;
        int ans;
        if(guy==0)ans=INT_MIN;
        else ans=INT_MAX;
        for(int i=0;i<3;i++){
            if(ind+i==n)break;
            curr+=nums[ind+i];
            if(guy==0)ans=max(ans,curr*mul+fun(!guy,ind+i+1,nums));
            else ans=min(ans,curr*mul+fun(!guy,ind+i+1,nums));
        }
        return dp[guy][ind]=ans;
    }
    string stoneGameIII(vector<int>& nums) {
        n=nums.size();
        dp.resize(2,vector<int>(n,-1));
        int ans=fun(0,0,nums);
        if(ans>0)return "Alice";
        else if(ans<0)return "Bob";
        return "Tie";

    }
};