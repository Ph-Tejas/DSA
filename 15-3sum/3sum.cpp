class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            
            mp[curr]++;
            if(mp[curr]>2&&curr!=0)mp[curr]=2;

        }
        vector<int>v;
        if(mp[0]>2){
            ans.push_back({0,0,0});
            mp[0]=1;
        }

        if(mp[0]==2)mp[0]=1;

        for(auto &val:mp){
            if(val.second==2){
                if(mp.find(-2*val.first)!=mp.end()){
                    ans.push_back({val.first,val.first,-2*val.first});
                }
                val.second=1;
            }
            if(val.second==1){
                v.push_back(val.first);
            }
        }
        mp.clear();
        vector<int>vis(2e5+1,-1);
        n=v.size();
        for(int i=0;i<n;i++){
            vis[v[i]+1e5]=i;
        }
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                int curr1=v[i];
                int curr2=v[j];
                int req=(-1*(curr1+curr2))+1e5;
                if(req<=2e5 && req>-1){
                    if(vis[req]>i && vis[req]>j){
                        ans.push_back({curr1,curr2,req-100000});
                    }
                }
            }
        }
        return ans;








    }
};