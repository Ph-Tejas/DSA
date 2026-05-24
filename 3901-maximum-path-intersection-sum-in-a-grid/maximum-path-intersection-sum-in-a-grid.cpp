class Solution {
public:
    int kadane(vector<int>v,int flag){
        int n=v.size();
        int sum=0;
        int ans=INT_MIN;
        int sz=0;
        for(int i=0;i<n;i++){
            if((!flag)&&(i!=0 && i!=n-1))ans=max(ans,v[i]);
            sum+=v[i];
            sz++;


            if((!(sz==1&&flag))&&(!(sz==1&&(i==0||i==n-1))))ans=max(ans,sum);
            if(sum<0){
                sum=0;
                sz=0;
            }
        }
        return ans;

    }
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            bool flag=false;
            if(i==0||i==n-1)flag=true;
            ans=max(ans,kadane(grid[i],flag));
        }
        for(int j=0;j<m;j++){
            vector<int>v;
            bool flag=false;
            if(j==0||j==m-1)flag=true;
            for(int i=0;i<n;i++){
                v.push_back(grid[i][j]);
            }
            ans=max(ans,kadane(v,flag));
        }
        for(int i=0;i<n;i++){
            if(i==0||i==n-1){
                for(int j=0;j<m-1;j++){
                    ans=max(ans,grid[i][j]+grid[i][j+1]);
                }
            }
            else{
                ans=max(ans,grid[i][0]+grid[i][1]);
                ans=max(ans,grid[i][m-1]+grid[i][m-2]);
                

            }
        }
        for(int j=0;j<m;j++){
            if(j==0||j==m-1){
                for(int i=0;i<n-1;i++){
                    ans=max(ans,grid[i][j]+grid[i+1][j]);
                }
            }
            else{
                ans=max(ans,grid[0][j]+grid[1][j]);
                ans=max(ans,grid[n-1][j]+grid[n-2][j]);
                

            }
        }
        return ans;
    }
};