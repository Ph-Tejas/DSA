class Solution {
public:
    int mod=1e9+7;
    bool isVisited(int vis,int k){
        return ((vis>>k)&1);
    }
    int tgt;
    long long fun(int hatNo,int vis,vector<vector<int>>&possible,vector<vector<long long>>&dp){
        if(vis==tgt){
            return 1LL;
        }
        if(hatNo==41){
            return 0*1LL;
        }
        if(dp[hatNo][vis]!=-1){
            return dp[hatNo][vis];
        }
        long long ans=0;
        for(int i=0;i<possible[hatNo].size();i++){
            int k=possible[hatNo][i];
            if(k==-1){
                ans+=fun(hatNo+1,vis,possible,dp);
                ans%=mod;
            }
            else{
                if(isVisited(vis,k))continue;
                int newVis=((vis|(1<<k)));

                ans+=fun(hatNo+1,newVis,possible,dp);
                ans%=mod;

            }
        }
        return dp[hatNo][vis]=ans;




    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        vector<vector<int>>possible(41,{-1});
        for(int i=0;i<n;i++){
            for(int j=0;j<hats[i].size();j++){
                possible[hats[i][j]].push_back(i);
            }
        }
        vector<vector<long long>>dp(41,vector<long long>((1<<(n)),-1));
        tgt=(1<<(n))-1;
        return fun(0,0,possible,dp)%mod;
        
    }
};