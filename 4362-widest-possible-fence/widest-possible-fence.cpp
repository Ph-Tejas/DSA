class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n=planks.size();
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mp[planks[i]]++;
            maxi=max(maxi,mp[planks[i]]);
        }

        vector<int>v;
        for(auto &val:mp){
            v.push_back(val.first);
            // cout<<v.back();
        }
        unordered_map<int,int>freq;
        int sz=v.size();
        for(int i=0;i<sz;i++){
            for(int j=i;j<sz;j++){

                if(i==j)freq[v[i]+v[j]]+=mp[v[i]]/2;


                else freq[v[i]+v[j]]+=min(mp[v[i]],mp[v[j]]);
                
            }
        }
        for(auto &val:freq){
            maxi=max(maxi,val.second+mp[val.first]);
        }
        
        return maxi;




    }
};