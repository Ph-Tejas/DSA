class Solution {
public:
    bool ans=true;
    vector<bool>vis;
    vector<vector<int>>adj;
    vector<int>pref;
    void fun(int node,int par,int prev){
        if(vis[node])return;
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==par)continue;
            int now=(!prev);
            if(pref[adj[node][i]]!=-1){
                if(pref[adj[node][i]]!=now)ans=false;
            }
            pref[adj[node][i]]=now;
            fun(adj[node][i],node,now);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int sz=dislikes.size();
        pref.resize(n+1,-1);
        adj.resize(n+1);
        vis.resize(n+1);
        
        for(int i=0;i<sz;i++){
            int a=dislikes[i][0];
            int b=dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            
            
        }
        for(int i=1;i<=n;i++){
            
            if(pref[i]!=-1)continue;
            pref[i]=1;
            fun(i,-1,1);
        }
        return ans;
    }
};