class Solution {
public:
    vector<int>dp;
    int n;
    int fun(int i,vector<int>& days, vector<int>& costs){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int curr=days[i];
        int ans=costs[0]+fun(i+1,days,costs);
        for(int it=i;it<n;it++){
            
            if(days[it]-curr<7)ans=min(ans,costs[1]+fun(it+1,days,costs));
            else break;
            
        }
        for(int it=i;it<n;it++){
            if(days[it]-curr<30)ans=min(ans,costs[2]+fun(it+1,days,costs));
            else break;
        }
        return dp[i]=ans;

        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        dp.resize(n,-1);
        return fun(0,days,costs);
        
    }
};