class Solution {
public:
    int mod=1e9+7;
    int n,m;
    vector<vector<pair<long long,long long>>>dp;

    pair<long long,long long>fun(vector<vector<int>>& grid,int i,int j){
        
        long long u=0;
        long long l=0;
        if(dp[i][j].first != -1)return dp[i][j];
        for(int d=0;d<=1;d++){
        
            
            int ni=i;
            int nj=j;
            if(d==0){
                ni-=1;

                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(grid[ni][nj]==0){
                        pair<long long,long long>pr=fun(grid,ni,nj);
                        u+=pr.first+pr.second;
                        if(ni==0 && nj==0){
                            u+=1;
                        }


                    }
                    else{
                        if(ni>=0 && nj-1>=0 && ni<n && nj-1<m){
                            if(grid[ni][nj-1]==0){
                                pair<long long,long long>pr=fun(grid,ni,nj-1);
                                u+=pr.first+pr.second;
                                if(ni==0 && nj-1==0){
                                    u+=1;
                                }


                            }
                            else{

                                pair<long long,long long>pr=fun(grid,ni,nj-1);
                                u+=pr.first;
                            }

                            

                        }
                    }

                }
                u%=mod;
                

            }
            else{
                nj-=1;

                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(grid[ni][nj]==0){
                        pair<long long,long long>pr=fun(grid,ni,nj);
                        l+=pr.first+pr.second;
                        if(ni==0 && nj==0){
                            l+=1;
                        }


                    }
                    else{
                        if(ni-1>=0 && nj>=0 && ni-1<n && nj<m){
                            if(grid[ni-1][nj]==0){
                                pair<long long,long long>pr=fun(grid,ni-1,nj);
                                l+=pr.first+pr.second;
                                if(ni-1==0 && nj==0){
                                    l+=1;
                                }

                            }
                            else{

                                pair<long long,long long>pr=fun(grid,ni-1,nj);
                                l+=pr.second;
                            }

                            

                        }
                    }
                }
                l%=mod;
            }




            
        }

        return dp[i][j]={u,l};
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.resize(n,vector<pair<long long,long long>>(m,{-1,-1}));
        
        pair<long long,long long>pr=fun(grid,n-1,m-1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j].first<<" "<<dp[i][j].second<<"    ";
        //     }
        //     cout<<endl;
        // }
        dp[0][0]={0,0};
        return (pr.first+pr.second)%mod;
    }
};