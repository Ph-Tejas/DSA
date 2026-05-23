class Solution {
public:
    
    vector<vector<vector<int>>> dp;

    int total;
    int n,m;

    int ans = INT_MAX;

    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

    void fun(int i,int j,int done,int dist,vector<string>& grid){

        if(dist>=ans)return;

        int curr=grid[i][j];

        if(curr<='z'&&curr>='a'){
            done|=(1<<(curr-'a'));
        }

        if(done==total){
            ans=min(ans,dist);
            return;
        }

        if(dp[i][j][done]<=dist){
            return;
        }

        dp[i][j][done]=dist;

        for(int it=0;it<4;it++){

            int nx=i+dir[it][0];
            int ny=j+dir[it][1];

            if(nx<n&&nx>=0&&ny<m&&ny>=0 && grid[nx][ny]!='#'){

                int nxt=grid[nx][ny];

                if(nxt<='Z'&&nxt>='A'){
                    if((done & (1<<(nxt-'A')))==0){
                        continue;
                    }
                }

                fun(nx,ny,done,dist+1,grid);
            }
        }
    }

    int shortestPathAllKeys(vector<string>& grid) {

        n=grid.size();
        m=grid[0].size();

        int st_r,st_c;

        int k=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                char curr=grid[i][j];

                if(curr=='@'){
                    st_r=i;
                    st_c=j;
                }

                else if(curr>='a'&&curr<='z'){
                    k++;
                }
            }
        }

        total=(1<<k)-1;

        dp.resize(
            n,
            vector<vector<int>>(m,vector<int>((1<<k),INT_MAX))
        );

        fun(st_r,st_c,0,0,grid);

        return (ans==INT_MAX)?-1:ans;
    }
};