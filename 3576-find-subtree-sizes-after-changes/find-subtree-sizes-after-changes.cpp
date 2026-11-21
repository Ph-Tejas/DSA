class Solution {
public:
    vector<vector<int>>adj,newAdj;
    vector<int>rearrange;
    vector<int>ans;
    void dfs(int node,string& s,vector<int>alpha,vector<int>& parent){
        

        if(alpha[s[node]-'a']==-1){
            rearrange[node]=parent[node];
            
        }
        else {
            rearrange[node]=alpha[s[node]-'a'];

        }
        alpha[s[node]-'a']=node;
        for(auto &val:adj[node]){
            dfs(val,s,alpha,parent);
        }




    }
    int fun(int node){
        int ct=1;
        for(auto &val:newAdj[node]){
            ct+=fun(val);
        }
        ans[node]=ct;
        return ct;
        

    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        adj.resize(n);
        newAdj.resize(n);
        rearrange.resize(n);
        for(int i=0;i<n;i++){
            if(i==0)continue;
            adj[parent[i]].push_back(i);
        }
        vector<int>alpha(26,-1);
        dfs(0,s,alpha,parent);

        for(int i=0;i<n;i++){
            if(i==0)continue;
            newAdj[rearrange[i]].push_back(i);
        }
        ans.resize(n);
        fun(0);

        return ans;






        




    }
};