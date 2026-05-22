class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>>grid(n,vector<int>(m));
        int i=0,j=0;
        while(i<n && j<m){
            if(rowSum[i]<colSum[j]){
                for(int k=m-1;k>j;k--){
                    grid[i][k]=0;
                }
                grid[i][j]=rowSum[i];

                colSum[j]-=rowSum[i];
                i++;
            }
            else{
                for(int k=n-1;k>i;k--){
                    grid[k][j]=0;
                }
                grid[i][j]=colSum[j];
                rowSum[i]-=colSum[j];
                j++;
            }
        }
        return grid;




    }
};