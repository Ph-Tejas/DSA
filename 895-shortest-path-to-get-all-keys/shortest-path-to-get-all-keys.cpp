class Solution {
public:
    
    int shortestPathAllKeys(vector<string>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int st_r, st_c;
        int k = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                char curr = grid[i][j];

                if(curr=='@'){
                    st_r=i;
                    st_c=j;
                }
                else if(curr>='a' && curr<='z'){
                    k++;
                }
            }
        }

        int total = (1<<k)-1;

        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        vector<vector<vector<bool>>> vis(
            n,
            vector<vector<bool>>(m,vector<bool>((1<<k),false))
        );

        queue<vector<int>> q;

        q.push({st_r,st_c,0,0});
        vis[st_r][st_c][0]=true;

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            int i = curr[0];
            int j = curr[1];
            int done = curr[2];
            int dist = curr[3];

            if(done==total)return dist;

            for(int it=0;it<4;it++){

                int nx = i + dir[it][0];
                int ny = j + dir[it][1];

                if(nx<0 || nx>=n || ny<0 || ny>=m)continue;

                char cell = grid[nx][ny];

                if(cell=='#')continue;

                int newMask = done;

                if(cell>='a' && cell<='z'){
                    newMask |= (1<<(cell-'a'));
                }

                if(cell>='A' && cell<='Z'){
                    if((newMask & (1<<(cell-'A')))==0){
                        continue;
                    }
                }

                if(vis[nx][ny][newMask])continue;

                vis[nx][ny][newMask]=true;

                q.push({nx,ny,newMask,dist+1});
            }
        }

        return -1;
    }
};