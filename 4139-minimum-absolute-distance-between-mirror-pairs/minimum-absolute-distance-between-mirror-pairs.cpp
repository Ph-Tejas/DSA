class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        vector<string>v,v1,v2;
        map<string,vector<int>>mp;
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            v.push_back(s);
            mp[s].push_back(i);
        }
        v1=v;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            while(v1[i].back()=='0'){
                v1[i].pop_back();
            }
            reverse(v1[i].begin(),v1[i].end());
            if(mp.find(v1[i])!=mp.end()){
                if((upper_bound(mp[v1[i]].begin(),mp[v1[i]].end(),i))!=mp[v1[i]].end()){
                    ans=min(ans,abs(((*upper_bound(mp[v1[i]].begin(),mp[v1[i]].end(),i)))-i));
                }

                // for(auto &val:mp[v1[i]]){
                //     if(val<=i)continue;
                //     ans=min(ans,abs(val-i));
                // }
            }
            

        }
        if(ans==INT_MAX)return -1;
        return ans;



    }
};