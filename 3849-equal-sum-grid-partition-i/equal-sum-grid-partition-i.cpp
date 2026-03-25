class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid_) {
        
        int n=grid_.size();
        int m=grid_[0].size();
        vector<vector<long long>> grid(n,vector<long long>(m));
for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=grid_[i][j];
            }

        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]=grid[i][j]+grid[i][j-1];
            }

        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                grid[i][j]=grid[i][j]+grid[i-1][j];
            }

        }
        int last=grid[n-1][m-1];
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==grid[n-1][m-1]-grid[i][m-1])return true;
        }
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==grid[n-1][m-1]-grid[n-1][j])return true;
        }
        return false;
        
        
    }
};