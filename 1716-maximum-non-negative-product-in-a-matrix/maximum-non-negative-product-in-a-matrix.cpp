class Solution {
public:
    long long mod=1e9+7;
    bool z;
    vector<vector<vector<long long>>>dp;
    long long fun(int i,int j,bool flag,vector<vector<int>>& grid){
        if(grid[i][j]==0)z=true;
        
        if(i==0&&j==0){
            bool sign=((grid[0][0]<0)?false:true);
            if((sign==true&&flag==true)||(sign==false&&flag==false)){
                return 1e18;
            }
            else{
                return grid[i][j];
            }
        }
        if(dp[i][j][flag]!=-1)return dp[i][j][flag];
        bool main_flag=false;
        if((grid[i][j]<0&&flag==false)||(grid[i][j]>=0&&flag==true)){
            main_flag=true;
        }
        long long a,b;
        if(i!=0){

            a=fun(i-1,j,main_flag,grid);
        }
        else a=1e18;
        if(j!=0){
            b=fun(i,j-1,main_flag,grid);
        }
        else b=1e18;
        long long ans;
        if(a==1e18&&b==1e18){
            ans=1e18;
        }
        else if(a==1e18){
            ans=b*grid[i][j];
        }
        else if(b==1e18){
            ans=a*grid[i][j];
        }
        else {
            if(main_flag){
                if(a<b){
                    ans=a*grid[i][j];
                }
                else{
                    ans=b*(grid[i][j]);
                }
            }
            else{
                if(a<b){
                    ans=b*grid[i][j];
                }
                else{
                    ans=a*(grid[i][j]);
                }
            }
        }
        return dp[i][j][flag]=ans;
        
    }
    int maxProductPath(vector<vector<int>>& grid) {
        long long n=grid.size();
        long long m=grid[0].size();
        z=false;
        dp.resize(n,vector<vector<long long>>(m,vector<long long>(2,-1)));
        
        long long ans=fun(n-1,m-1,false,grid);
        if(ans==1e18){
            if(z)return 0;
            return -1;
        }
        return (ans%mod);
        
    }
};