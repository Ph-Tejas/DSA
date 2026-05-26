class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));
        vector<int>ans;
        pair<int,int>a={0,0};
        pair<int,int>b={0,m-1};
        pair<int,int>c={n-1,m-1};
        pair<int,int>d={n-1,0};
        for(int t=0;t<n;t++){
            if(vis[a.first][a.second]){
                break;
            }
            for(int i=a.second;i<=b.second;i++){
                if(vis[a.first][i])continue;
                ans.push_back(matrix[a.first][i]);
                vis[a.first][i]=true;
            }

            for(int i=b.first+1;i<=c.first;i++){
                if(vis[i][b.second])continue;
                ans.push_back(matrix[i][b.second]);
                vis[i][b.second]=true;
            }

            for(int i=c.second-1;i>=d.second;i--){
                if(vis[c.first][i])continue;
                ans.push_back(matrix[c.first][i]);
                vis[c.first][i]=true;
            }

            for(int i=d.first-1;i>a.first;i--){
                if(vis[i][d.second])continue;
                ans.push_back(matrix[i][d.second]);
                vis[i][d.second]=true;
            }
            a.first+=1;
            a.second+=1;
            b.first+=1;
            b.second-=1;
            c.first-=1;
            c.second-=1;
            d.first-=1;
            d.second+=1;

        }
        return ans;
    }
};