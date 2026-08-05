class Solution {
public:
    vector<vector<bool>>vis;
    vector<pair<int,int>>v1;
    vector<pair<int,int>>v2;
    int n;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& grid,bool first){
        if(vis[i][j])return;
        vis[i][j]=true;
        
        if(first)v1.push_back({i,j});
        
        else v2.push_back({i,j});

        for(int it=0;it<4;it++){
            int ni=i+dir[it][0];
            int nj=j+dir[it][1];
            if(ni>=0 &&nj>=0 &&nj<=n-1 &&ni<=n-1 &&grid[ni][nj]==1 && !vis[ni][nj]){
                dfs(ni,nj,grid,first);
            }
        }

    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        vis.resize(n,vector<bool>(n));
        bool first=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,first);
                    first=false;
                }
            }
        }

        int sz1=v1.size();
        int sz2=v2.size();
        int mini=INT_MAX;
        for(int i=0;i<sz1;i++){
            for(int j=0;j<sz2;j++){

                mini=min(mini,abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second)-1);




            }
        }
        return mini;




    }
};