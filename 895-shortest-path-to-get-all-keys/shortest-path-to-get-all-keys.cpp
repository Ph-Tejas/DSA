class Solution {
public:

    int ans = INT_MAX;
    int n,m,total;

    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i,int j,int mask,int dist,
             vector<string>& grid,
             vector<vector<vector<int>>>& best){

        if(dist >= ans)return;

        char curr = grid[i][j];

        if(curr>='a' && curr<='z'){
            mask |= (1<<(curr-'a'));
        }

        if(mask==total){
            ans=min(ans,dist);
            return;
        }

        if(best[i][j][mask] <= dist)return;

        best[i][j][mask]=dist;

        for(int k=0;k<4;k++){

            int nx=i+dir[k][0];
            int ny=j+dir[k][1];

            if(nx<0 || ny<0 || nx>=n || ny>=m)continue;

            char nxt = grid[nx][ny];

            if(nxt=='#')continue;

            if(nxt>='A' && nxt<='Z'){
                if((mask & (1<<(nxt-'A')))==0){
                    continue;
                }
            }

            dfs(nx,ny,mask,dist+1,grid,best);
        }
    }

    int shortestPathAllKeys(vector<string>& grid) {

        n=grid.size();
        m=grid[0].size();

        int sr,sc;
        int k=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='@'){
                    sr=i;
                    sc=j;
                }

                else if(grid[i][j]>='a' && grid[i][j]<='z'){
                    k++;
                }
            }
        }

        total=(1<<k)-1;

        vector<vector<vector<int>>> best(
            n,
            vector<vector<int>>(m,vector<int>((1<<k),INT_MAX))
        );

        dfs(sr,sc,0,0,grid,best);

        return ans==INT_MAX ? -1 : ans;
    }
};