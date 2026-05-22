class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int>v(n);
        int sz=edges.size();
        int q=queries.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<sz;i++){
            v[edges[i][0]-1]++;
            v[edges[i][1]-1]++;
            mp[{min(edges[i][0]-1,edges[i][1]-1),max(edges[i][0]-1,edges[i][1]-1)}]++;
        }
        vector<int>v1=v;
        int que,curr;
        int ans1=0;
        int ct=0;
        vector<int>ans(q);
        sort(v.begin(),v.end());
        for(int i=0;i<q;i++){
            ans1=0;
            que=queries[i];
            for(int j=0;j<n-1;j++){
                curr=v[j];
                ct=v.end()-upper_bound(v.begin(),v.end(),que-curr);
                ans1+=min(n-1-j,ct);
            }
            for(auto &val:mp){
                if(v1[val.first.first]+v1[val.first.second]>que&&v1[val.first.first]+v1[val.first.second]-val.second<=que)ans1--;
            }
            ans[i]=ans1;



        }
        return ans;
    }
};