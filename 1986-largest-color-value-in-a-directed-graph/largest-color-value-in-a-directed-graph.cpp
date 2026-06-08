class Solution {
public:
    int maxi=0;
    vector<vector<int>>dp;
    vector<vector<int>>adj;
    vector<bool>done;
    vector<bool>vis;
    vector<int>fun(int node,string &colors){
        if(vis[node]){
            
            return dp[node]={(int)1e9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        }
        if(done[node]){
            return dp[node];
        }
        vis[node]=true;
        vector<int>ans(26);
        for(int j=0;j<adj[node].size();j++){

            for(int k=0;k<26;k++){
                

                if(k==colors[node]-'a'){
                    if(done[adj[node][j]]){
                        ans[k]=max(ans[k],1+dp[adj[node][j]][k]);
                    }
                    
                    else ans[k]=max(ans[k],1+fun(adj[node][j],colors)[k]);
                }
                else{
                    if(done[adj[node][j]]){
                        ans[k]=max(ans[k],dp[adj[node][j]][k]);
                    }
                    else ans[k]=max(ans[k],fun(adj[node][j],colors)[k]);
                }



            }
            


        }
        if(adj[node].size()==0){
            ans[colors[node]-'a']=1;
        }
        vis[node]=false;
        done[node]=true;
        return dp[node]=ans;

        
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        int sz=edges.size();

        dp.resize(n,vector<int>(26,-1));
        vis.resize(n,false);
        adj.resize(n);
        done.resize(n,false);
        for(int i=0;i<sz;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++){
            
            
            int mx=0;
            for(int k=0;k<26;k++){
                if(done[i]){
                    mx=max(dp[i][k],mx);
                }
                else mx=max(mx,fun(i,colors)[k]);
            }
            maxi=max(mx,maxi);

            
        }
        return ((maxi>=1e9)?-1:maxi);










    }
};