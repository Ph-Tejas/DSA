class Solution {
public:
    vector<unordered_map<int,int>>v;
    int n;
    int dp[101][5001];
    int fun(int i,int sum){
        if(sum==0)return 0;
        if(i==n)return 1e9;
        if(dp[i][sum]!=-1)return dp[i][sum];

        int mini=INT_MAX;
        for(auto &val:v[i]){
            if(sum<val.first)continue;
            mini=min(mini,val.second+fun(i+1,sum-val.first));
        }
        return dp[i][sum]=mini;


    }
    int minOperations(vector<int>& nums, int sum) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int it=0;
            int id=nums[i];
            while(id!=0){
                mp[id]=it;
                id/=2;
                it++;

            }
            id=nums[i];
            it=0;
            while(id<=sum){
                mp[id]=it;
                id*=2;
                it++;
            }
            mp[0]=0;
            v.push_back(mp);
        }
        int ans=fun(0,sum);
        if(ans>=1e9)return -1;
        return ans;




    }
};