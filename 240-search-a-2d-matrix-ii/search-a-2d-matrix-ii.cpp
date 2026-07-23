class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        // bool ans=false; 
        for(int i=0;i<n;i++){
            auto it=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(it==m)continue;
            if(matrix[i][it]==target)return true;
        }
        return false;
    }
};