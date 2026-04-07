class Solution {
public:
    int n;
    vector<vector<int>>dp,temp;
    vector<vector<bool>>dont_come,temp1;

    int fun(int vis,int node,vector<vector<int>>& graph){
        if(vis==((1<<n)-1))return 0;
        if(dp[node][vis]!=-1&&dp[node][vis]<100){
            return dp[node][vis];
        }
        dont_come[node][vis]=true;
        int mini=1e8;
        
        for(int i=0;i<graph[node].size();i++){
            
            int curr=graph[node][i];
            int new_vis = vis | (1 << curr);
            if(dont_come[curr][new_vis])continue;
            mini=min(mini,1+fun(new_vis,curr,graph));
        }
        dont_come[node][vis]=false;
        return dp[node][vis]=mini;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        
        
        n=graph.size();
        
        dp.resize(n,vector<int>((1<<(n)),-1));
        
        dont_come.resize(n,vector<bool>((1<<(n)),false));
        temp=dp;
        temp1=dont_come;

        
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            dp=temp;
            dont_come=temp1;
            mini=min(mini,(fun((1<<i),i,graph)));
        }
        return mini;

    }
};