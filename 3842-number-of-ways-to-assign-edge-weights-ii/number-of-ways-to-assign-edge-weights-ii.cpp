class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>adj;
    vector<int>levels;
    vector<int>parents;
    vector<int>powy;
    void findLevels(int node,int level,int par){
        parents[node]=par;
        levels[node]=level;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]!=par){
                findLevels(adj[node][i],level+1,node);
            }
        }
    }
    vector<vector<int>>dp;
    int createDp(int node,int j){
        
        if(j==0){
            return dp[node][j]=parents[node];
        }
        if(dp[node][j]!=-10){
            return dp[node][j];
        }
        
        return dp[node][j]=createDp(dp[node][j-1],j-1);
    }
    int shift(int b,int k){
        int i=0;
        while(k>0){
            if(k&1){
                b=dp[b][i];
            }
            k/=2;
            i++;
        }
        return b;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        powy.push_back(1);
        int n=edges.size()+1;
        for(int i=1;i<=1e5;i++){
            powy.push_back((powy.back()*2)%mod);
        }
        int qn=queries.size();
        adj.resize(n+1);
        dp.resize(n+1,vector<int>(20,-10));
        
        levels.resize(n+1);
        
        parents.resize(n+1);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        findLevels(1,0,-1);

        for(int i=1;i<=n;i++){
            for(int j=0;j<20;j++){
                
                if(levels[i]<powy[j]){
                    dp[i][j]=-1;
                    continue;
                }
                if(dp[i][j]!=-10){
                    continue;
                }
                createDp(i,j);


            }
        }
        vector<int>ans;
        for(int q=0;q<qn;q++){
            int a=queries[q][0];
            int b=queries[q][1];
            if(a==b){
                ans.push_back(0);
                continue;
            }
            if(levels[a]>levels[b]){
                swap(a,b);
            }
            int total=abs(levels[a]-levels[b]);
            
            b=shift(b,total);
            if(a==b)ans.push_back(powy[total-1]);
            else{
                int lj=19;
                while(lj>=0){
                    if(dp[a][lj]!=dp[b][lj]){
                        a=dp[a][lj];
                        b=dp[b][lj];
                        total+=2*powy[lj];
                    }
                    lj--;
                }
                total+=2;
                ans.push_back(powy[total-1]);

            }

            
            
        }
        return ans;
        return {};


    }
};