class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{1,1}};
    int mod=1e9+7;
    int n;
    int m;
    vector<vector<vector<long long>>>dp;
    long long fun(int i,int j,int sum,vector<string>& board){
        // cout<<i<<" "<<j<<" "<<sum<<endl;
        if(i==n-1  && j==m-1){
            if(sum==0)return 1LL;
            else return 0;
        }
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];


        long long ans=0;
        
        for(int d=0;d<3;d++){
            int ni=i+dir[d][0];
            int nj=j+dir[d][1];

            if(ni>-1 && nj>-1 && ni<n && nj<m && board[ni][nj]!='X'){

                ans+=fun(ni,nj,sum-(board[i][j]-'0'),board);
                ans%=mod;

            }
        }
        return dp[i][j][sum]=ans;







    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();

        board[0][0]='0';
        board[n-1][m-1]='0';
        

        vector<vector<int>>maxDist(n,vector<int>(m,-1));
        maxDist[0][0]=0;
        for(int i=1;i<n;i++){
            char ch=board[i][0];
            if(ch=='X')break;
            maxDist[i][0]=maxDist[i-1][0]+(ch-'0');
        }
        for(int i=1;i<m;i++){
            char ch=board[0][i];
            if(ch=='X')break;
            maxDist[0][i]=maxDist[0][i-1]+(ch-'0');
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                char ch=board[i][j];
                
                if(ch!='X'){
                    int mx=-1;
                    for(int d=0;d<3;d++){
                        int ni=i-dir[d][0];
                        int nj=j-dir[d][1];

                        if(ni>-1 && nj>-1 && ni<n && nj<m){
                        
                            mx=max(mx,maxDist[ni][nj]);

                        }
                    }
                    if(mx==-1)continue;
                    maxDist[i][j]=mx+(ch-'0');
                }
            }
        }

        int maxi=maxDist[n-1][m-1];
        if(maxi==-1)return {0,0};
        
        

        dp.resize(n,vector<vector<long long>>(m,vector<long long>(maxi+1,-1)));

        return {maxi,(int)fun(0,0,maxi,board)};



    }
};