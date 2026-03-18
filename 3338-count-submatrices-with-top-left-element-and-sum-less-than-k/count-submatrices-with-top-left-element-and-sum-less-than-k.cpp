class Solution {
public:
    int countSubmatrices(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=matrix[i][j];
                matrix[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=matrix[j][i];
                if(sum<=k)ans++;
            }
        }
        return ans;
    }
};