class Solution {
public:
    vector<vector<int>>adj;
    vector<vector<int>>cf;
    vector<int>ans;
    vector<int>vis;
    vector<int> fun(int node,int par,int &n,string &labels){
        int ch=labels[node]-'a';
        vector<int>vv(26);
        if(vis[node]!=-1)return cf[node];
        for(int i=0;i<adj[node].size();i++){
            if(par==adj[node][i])continue;
            vector<int>v=fun(adj[node][i],node,n,labels);
            for(int j=0;j<26;j++){
                vv[j]+=v[j];
            }

        }
        vv[ch]++;
        ans[node]=vv[ch];
        vis[node]=1;
        return cf[node]=vv;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        ans.resize(n);
        vis.resize(n,-1);
        int sz=edges.size();
        for(int i=0;i<sz;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        cf.resize(n,vector<int>(26));
        fun(0,-1,n,labels);
        return ans;

    }
};