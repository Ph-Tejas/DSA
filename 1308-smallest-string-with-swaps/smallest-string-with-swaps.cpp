class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>vis;
    void dfs(int node,string &s,vector<int>&sam,string &ssam){
        if(vis[node])return;
        vis[node]=true;
        sam.push_back(node);
        ssam.push_back(s[node]);
        for(int i=0;i<adj[node].size();i++){
            int curr=adj[node][i];
            if(vis[curr])continue;
            dfs(curr,s,sam,ssam);

        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        int sz=pairs.size();
        adj.resize(n);
        vis.resize(n);
        for(int i=0;i<sz;i++){
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> sam;
                string ssam;

                dfs(i,s,sam,ssam);
                sort(ssam.begin(),ssam.end());
                sort(sam.begin(),sam.end());
                int it=0;
                for(auto &ind:sam){
                    s[ind]=ssam[it];
                    it++;
                }

            }
        }
        return s;
    }
};