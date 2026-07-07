class Solution {
public:
    vector<vector<int>>adj;
    vector<set<int>>v;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int sz=prerequisites.size();
        int n=numCourses;

        int que=queries.size();
        v.resize(n);
        adj.resize(n);
        
        vector<int>indeg(n);
        for(int i=0;i<sz;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indeg[prerequisites[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);

            }
        }
        while(!q.empty()){
            int node=q.front();

            q.pop();
            v[node].insert(node);
            for(int i=0;i<adj[node].size();i++){
                int curr=adj[node][i];
                indeg[curr]--;
                if(indeg[curr]==0){
                    q.push(curr);
                    
                }
                for(auto &val:v[node]){
                    v[curr].insert(val);
                }
            }
        }
        vector<bool>ans;
        for (int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
        
            if(v[b].find(a)!=v[b].end()){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;





    }
};