class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{1,1}};
    int mod=1e9+7;
    int n;
    int m;
  
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();

        board[0][0]='0';
        board[n-1][m-1]='0';
        

        vector<vector<pair<int,int>>>maxDist(n,vector<pair<int,int>>(m,{-1,-1}));
        maxDist[0][0].first=0;
        maxDist[0][0].second=1;
        
        for(int i=1;i<n;i++){
            char ch=board[i][0];
            if(ch=='X')break;
            maxDist[i][0].first=maxDist[i-1][0].first+(ch-'0');
            maxDist[i][0].second=1;
            
        }
        for(int i=1;i<m;i++){
            char ch=board[0][i];
            if(ch=='X')break;
            maxDist[0][i].first=maxDist[0][i-1].first+(ch-'0');
            maxDist[0][i].second=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                char ch=board[i][j];
                
                if(ch!='X'){
                    int mx=-1;
                    map<int,long long>mp;
                    for(int d=0;d<3;d++){
                        int ni=i-dir[d][0];
                        int nj=j-dir[d][1];

                        if(ni>-1 && nj>-1 && ni<n && nj<m){
                            mx=max(mx,maxDist[ni][nj].first);
                            mp[maxDist[ni][nj].first]+=maxDist[ni][nj].second;
                            mp[maxDist[ni][nj].first]%=mod;


                        }
                    }
                    if(mx==-1)continue;
                    maxDist[i][j].first=mx+(ch-'0');
                    maxDist[i][j].second=mp[mx];

                }
            }
        }

        int maxi=maxDist[n-1][m-1].first;
        if(maxi==-1)return {0,0};
        return {maxi,maxDist[n-1][m-1].second};

        
        

       


    }
};