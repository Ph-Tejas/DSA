class Solution {
public:


    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int n,m;
    bool fun(int r, int c, vector<vector<int>>& grid){

        // Outside grid -> island is open
        if(r < 0 || r >= n || c < 0 || c >= m)
            return false;

        // Water or already visited
        if(grid[r][c] == 1)
            return true;

        // Mark visited
        grid[r][c] = 1;

        bool closed = true;

        for(int d = 0; d < 4; d++){
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];

            closed = fun(nr, nc, grid) && closed;
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<i<<" "<<j<<endl;
                if(grid[i][j]==2||grid[i][j]==1)continue;
                if(fun(i,j,grid))ct++;
            }
        }
        return ct;



    }
};