class Solution {
public:
    int countSubmatrices(vector<vector<int>>& matrix, int k) {
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum+=matrix[i][j];
                matrix[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<matrix[0].size();i++){
            int sum=0;
            for(int j=0;j<matrix.size();j++){
                sum+=matrix[j][i];
                if(sum<=k)ans++;
            }
        }
        return ans;
    }
};