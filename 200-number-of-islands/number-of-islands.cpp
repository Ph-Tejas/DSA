class Solution {
public:
    int n,m; 
    vector<vector<bool>>vis;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i,int j,vector<vector<char>>& grid){
        vis[i][j]=true;
        for(int it=0;it<4;it++){
            int ni=i+dir[it][0];
            int nj=j+dir[it][1];
            if(ni<n&&nj<m&&ni>-1&&nj>-1&&vis[ni][nj]==false&&grid[ni][nj]=='1'){
                dfs(ni,nj,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.resize(n,vector<bool>(m,false));

        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || grid[i][j]=='0')continue;

                ct++;
                dfs(i,j,grid);


            }
        }
        return ct;
    }
};