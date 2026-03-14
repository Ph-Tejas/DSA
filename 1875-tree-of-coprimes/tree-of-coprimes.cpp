class Solution {
public:
    vector<int>ans;
    vector<vector<int>> adj;
    vector<vector<bool>> coprime;
    void dfs(int node,int par,vector<vector<int>>&cps,vector<int>& nums,int level){
        int maxi=-1;
        for(int i=1;i<=50;i++){
            if(coprime[nums[node]][i]){
                
                if(maxi<cps[i][0]){
                    maxi=cps[i][0];
                    ans[node]=cps[i][1];
                }
            }
        }


        
        int prevLevel = cps[nums[node]][0];
        int prevNode = cps[nums[node]][1];

        cps[nums[node]][0]=level;
        cps[nums[node]][1]=node;

        for(int child : adj[node]){
            if(child==par) continue;
            dfs(child,node,cps,nums,level+1);
        }

        // restore state
        cps[nums[node]][0]=prevLevel;
        cps[nums[node]][1]=prevNode;

    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        ans.resize(n,-1);
        adj.resize(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        coprime.resize(51, vector<bool>(51, false));
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                coprime[i][j] = (__gcd(i, j) == 1);
            }
        }
        vector<vector<int>>cps(51,vector<int>(2,-1));

        dfs(0,-1,cps,nums,0);
        return ans;


    }
};