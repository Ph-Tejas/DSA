class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();
        vector<unordered_set<int>>v(n);
        for(int i=0;i<m;i++){
            v[0].insert(mat[0][i]);
        }
        for(int i=1;i<n;i++){
            for(auto &val:v[i-1]){
                for(int j=0;j<m;j++){
                    v[i].insert(mat[i][j]+val);
                }
            }
        }
        int ans=1e9;
        for(auto &val:v[n-1]){
            ans=min(ans,abs(target-val));
        }
        return ans;
    }
};