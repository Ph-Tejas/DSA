class Solution {
public:
    int n,m;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool ans=false;
    vector<bool>viss;

    vector<vector<int>>adj;
    void dfs(int node,int par,vector<vector<char>>& grid){
        viss[node]=true;
        for(int i=0;i<adj[node].size();i++){
            int curr=adj[node][i];
            if(par==curr)continue;
            if(viss[curr]){
                ans=true;
                continue;
            }
            dfs(curr,node,grid);
        }


    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid[0].size();
        n=grid.size();
        viss.resize(n*m);
        adj.resize(n*m);
        vector<bool>done(n*m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=grid[i][j];
                done[i*m+j]=true;
                for(int it=0;it<4;it++){
                    int ni=i+dir[it][0];
                    int nj=j+dir[it][1];

                    if(ni>-1 && ni<n && nj>-1 && nj<m && ch==grid[ni][nj]){
                        if(done[ni*m+nj])continue;
                        adj[ni*m+nj].push_back(i*m+j);
                        adj[i*m+j].push_back(ni*m+nj);

                        
                    }



                }
            }
        }
        for(int i=0;i<n*m;i++){
            if(viss[i])continue;
            if(ans)break;
            dfs(i,-1,grid);
        }
        return ans;

    }
};