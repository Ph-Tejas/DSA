class DSU{
public:
    vector<int> parent,rank;
    vector<vector<vector<int>>>adj;
    DSU(int n){
        for(int i=0;i<n+1;i++){
            parent.push_back(i);
        }
        rank.resize(n+1);
        adj.resize(n+1);
    }
    int findUpar(int a){
        if(a==parent[a])return a;
        return parent[a]=findUpar(parent[a]);
    }
    void join(int u,int v,int dist){
        int ult_u=findUpar(u);
        int ult_v=findUpar(v);
        if(ult_u==ult_v)return;
        adj[u].push_back({v,dist});
        adj[v].push_back({u,dist});
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;
        }
        else {
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
        
    }

};
class Solution {
public:
    int mini=INT_MAX;
    int N;
    void dfs(int node,int par,vector<vector<vector<int>>>&adj){
        
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i][0]==par)continue;
            mini=min(mini,adj[node][i][1]);
            dfs(adj[node][i][0],node,adj);
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        N=n;
        int sz=roads.size();
        sort(roads.begin(),roads.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        DSU ds(n+1);

        for(int i=0;i<sz;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            ds.join(u,v,roads[i][2]);





        }
        dfs(1,-1,ds.adj);
        return mini;
        




    }
};