class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        map<int,int>mp;

        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(curr&1){
                v.push_back({curr,i});
                v.push_back({curr*2,i});
                // mp[i]+=2;
            }
            else{
                while(!(curr&1)){
                    v.push_back({curr,i});
                    // mp[i]++;
                    curr/=2;
                }
                v.push_back({curr,i});
                // mp[i]++;
            }
        }



        sort(v.begin(),v.end());
        int ans=INT_MAX;
        int st=0;
        n=v.size();
        int en=0;

        int sz=nums.size();
        for(en;en<n;en++){
            if(mp.size()!=sz){
                mp[v[en].second]++;
                if(mp.size()==sz){
                    
                    break;
                }
            }
        }
        

        while(st<en){
            while(st<en){
                ans=min(ans,v[en].first-v[st].first);
                mp[v[st].second]--;
                if(mp[v[st].second]==0){
                    mp.erase(v[st].second);
                    en++;
                    st++;
                    break;
                }
                
                
                st++;

            }
            for(en;en<n;en++){
                if(mp.size()!=sz){
                    mp[v[en].second]++;
                    if(mp.size()==sz){

                        break;
                    }
                }
            }
            if(en==n)break;
        }

        
        return ans;
    }
};