class Solution {
public:
    int n;
    int dp[500001];
    vector<int>loc;
    vector<vector<int>>overall;
    int fun(int idx, vector<int>& profit){
   
        if(idx==n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        return dp[idx]=max(fun(idx+1,profit),overall[idx][2]+fun(loc[idx],profit));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        startTime.push_back(INT_MAX);
        for(int i=0;i<n;i++){
            overall.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(startTime.begin(),startTime.end());
        
        sort(overall.begin(),overall.end());
        for(int i=0;i<n;i++){
        
            loc.push_back((lower_bound(startTime.begin(),startTime.end(),overall[i][1]))-startTime.begin());
            
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,profit);
        

        
        











    }
};