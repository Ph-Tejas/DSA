class Solution {
public:
    vector<vector<vector<int>>>adj;
    vector<int>dist;
    vector<long long>dp;
    int mod=1e9+7;
    long long fun(int node,int &n){
        long long ans=0;
        if(node==n)return 1;
        if(dp[node]!=-1)return dp[node];
        for(auto &val:adj[node]){
            int newNode=val[0];
            if(dist[node]>dist[newNode]){
                ans+=fun(newNode,n);
                ans%=mod;
            }
        }
        return dp[node]=ans;




    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        adj.resize(n+1);
        int sz=edges.size();
        for(int i=0;i<sz;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        dist.resize(n+1,INT_MAX);
        dp.resize(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,n});
        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            if(dist[node]<=cost)continue;
            dist[node]=cost;

            for(auto &val:adj[node]){
                int newCost=cost+val[1];
                int newNode=val[0];
                if(newCost>=dist[newNode])continue;
                pq.push({newCost,newNode});

            }

        }
        

        return fun(1,n);

















    }
};