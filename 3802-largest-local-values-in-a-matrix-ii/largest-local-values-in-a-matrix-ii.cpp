class Solution {
public:
    int n,m;
    
    vector<vector<vector<int>>>grid;
    bool isReq(int i, int j,vector<vector<int>>& matrix){
        int num=matrix[i][j];
        int fw_i=i+num;
        int fw_j=j+num;
        int pv_i=i-num-1;
        int pv_j=j-num-1;
        
        if(fw_i>=n)fw_i=n-1;
        if(fw_j>=m)fw_j=m-1;
        if(pv_i<0)pv_i=-1;
        if(pv_j<0)pv_j=-1;
        vector<int>g=grid[fw_i][fw_j];
        if(pv_i==-1&&pv_j!=-1){
            for(int it=0;it<201;it++){
                g[it]-=grid[fw_i][pv_j][it];
            }
        }
        else if(pv_j==-1&&pv_i!=-1){
            for(int it=0;it<201;it++){
                g[it]-=grid[pv_i][fw_j][it];
            }
        }
        else if(pv_j!=-1&&pv_i!=-1){
            for(int it=0;it<201;it++){
                g[it]-=grid[pv_i][fw_j][it];
                g[it]-=grid[fw_i][pv_j][it];
                g[it]+=grid[pv_i][pv_j][it];
            }


        }
        if(i-num>=0&&j-num>=0){
            g[matrix[i-num][j-num]]--;
        }
        if(i-num>=0&&j+num<m){
            g[matrix[i-num][j+num]]--;
        }
        if(i+num<n&&j-num>=0){
            g[matrix[i+num][j-num]]--;
        }
        if(i+num<n&&j+num<m){
            g[matrix[i+num][j+num]]--;
        }
        for(int it=num+1;it<201;it++){
            if(g[it]!=0)return false;
        }
        return true;
        

    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        n=matrix.size();
        int ct=0;
        m=matrix[0].size();
        grid.resize(n,vector<vector<int>>(m,vector<int>(201)));
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(j==0){
                    grid[i][j][matrix[i][j]]++;
                    continue;
                }
                grid[i][j]=grid[i][j-1];
                grid[i][j][matrix[i][j]]++;
                

            }
        }
        for(int i=0;i<m;i++){

            for(int j=1;j<n;j++){
                
                for(int k=0;k<201;k++){
                    grid[j][i][k]+=grid[j-1][i][k];
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)continue;
                if(isReq(i,j,matrix)){
                    ct++;
                }
            }
        }
        return ct;
    }
};