class Solution {
public:
    int n;
    int sum=0;
    pair<int,int>pr={-1,-1};
    pair<int,int> fun(int i,int k,vector<vector<pair<int,int>>>&dp,vector<vector<int>>& costs){
        if(k==0){
            return {0,sum};
        }
        if(n-i<k){
            return {1e9,0};
        }
        if(dp[i][k]!=pr)return dp[i][k];
        int a=fun(i+1,k,dp,costs).second;

        int b=fun(i+1,k,dp,costs).first;
        int c=fun(i+1,k-1,dp,costs).second-costs[i][1];
        int d=fun(i+1,k-1,dp,costs).first+costs[i][0];
        
        if(a+b>c+d){
            return dp[i][k]={d,c};
        }
        else return dp[i][k]={b,a};
        return pr;





    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>v;
        n=costs.size();

        for(int i=0;i<n;i++){
            sum+=costs[i][1];
        }
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n/2+1,pr));
        return fun(0,n/2,dp,costs).first+fun(0,n/2,dp,costs).second;
        
    }
};