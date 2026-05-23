class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string>v=strs;
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            sort(v[i].begin(),v[i].end());
            mp[v[i]].push_back(i);
        }
        vector<vector<string>>ans(mp.size());
        int it=0;
        for(auto val:mp){
            for(int i=0;i<val.second.size();i++){
                ans[it].push_back(strs[val.second[i]]);

            }
            it++;
        }
        return ans;


    }
};