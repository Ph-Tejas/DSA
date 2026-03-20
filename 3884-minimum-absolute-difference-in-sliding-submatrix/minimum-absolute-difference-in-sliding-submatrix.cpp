class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        

        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
        if(k==1)return ans;
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                set<int>v;
                for(int i_=0;i_<k;i_++){
                    for(int j_=0;j_<k;j_++){
                        v.insert(grid[i+i_][j+j_]);
                    }
                }
                int a=*(v.begin());
                int mini=1000000;
                for(auto val:v){
                    if(val==a)continue;

                    mini=min(mini,val-a);
                    a=val;
                }
                ans[i][j]=mini;
                if(mini==1000000)ans[i][j]=0;
            }
        }
        return ans;

    }
};