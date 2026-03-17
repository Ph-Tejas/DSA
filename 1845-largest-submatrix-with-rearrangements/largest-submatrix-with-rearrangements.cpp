class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++){
            int ct=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]==0){
                    ct=0;

                }
                else ct+=1;
                matrix[j][i]=ct;

            }
        }
        int ans=INT_MIN;
        

        for(int i=0;i<n;i++){
            sort(matrix[i].begin(),matrix[i].end());
            int maxi=INT_MIN;
            for(int j=m-1;j>-1;j--){
                maxi=max(maxi,matrix[i][j]*(m-j));
            }
            ans=max(ans,maxi);
        }
        return ans;
    }
};