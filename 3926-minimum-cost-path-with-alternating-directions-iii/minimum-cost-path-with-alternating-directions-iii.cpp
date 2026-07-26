class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& penalty) {

        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(2)));
        pq.push({1,0,0,1});
        while(!pq.empty()){
            long long cost=pq.top()[0];
            long long i=pq.top()[1];
            long long j=pq.top()[2];
            long long atp=pq.top()[3];

            pq.pop();
            if(vis[i][j][atp])continue;
            vis[i][j][atp]=true;
            if(i==n-1&&j==m-1)return cost;
            long long u=INT_MAX,d=INT_MAX,w=INT_MAX,r=INT_MAX,l=INT_MAX;
            
            if(!vis[i][j][!atp]){
                pq.push({cost+penalty[i][j],i,j,!atp});

            }
            if(i+1<n && (!vis[i+1][j][!atp])){
                if(atp){
                    pq.push({cost+((i+2)*(j+1)),i+1,j,!atp});
                }
                else pq.push({cost+((i+2)*(j+1))+penalty[i][j],i+1,j,!atp});
            }
            if(j+1<m && (!vis[i][j+1][!atp])){
                if(atp){
                    pq.push({cost+((i+1)*(j+2)),i,j+1,!atp});
                }
                else pq.push({cost+((i+1)*(j+2))+penalty[i][j],i,j+1,!atp});
            }
            if(i-1>-1 && (!vis[i-1][j][!atp])){
                if(!atp){
                    pq.push({cost+((i)*(j+1)),i-1,j,!atp});
                }
                else pq.push({cost+((i)*(j+1))+penalty[i][j],i-1,j,!atp});
            }
            if(j-1>-1 && (!vis[i][j-1][!atp])){
                if(!atp){
                    pq.push({cost+((i+1)*(j)),i,j-1,!atp});
                }
                else pq.push({cost+((i+1)*(j))+penalty[i][j],i,j-1,!atp});
            }
        
        }
        return -1;



    }
};