class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        map<int,vector<int>>powy;
        
        for(int i=0;i<n;i++){
            
            int curr=nums[i];
            mp[curr]++;
            if(powy.find(curr)!=powy.end()||nums[i]==1)continue;
            
            powy[curr].push_back(curr);
            long long sample=(long long)curr*curr;
            while(sample<=(long long)1e9){
                powy[curr].push_back(sample);
                sample*=sample;
            }


        }
        int ans=max(1,((mp[1]&1)?mp[1]:mp[1]-1));


        
        for(auto &val:mp){
            int curr=val.first;
            if(curr==1)continue;
            if(val.second>=2){
                int ct=2;

                int i=2;
                while(true){
                    if((i/2)>=powy[curr].size())break;
                    
                    
                    int num=powy[curr][i/2];
                    
                    if(mp.find(num)!=mp.end()){
                        if(mp[num]>=2){
                            ct+=2;
                            ans=max(ans,ct-1);
                            i+=2;
                        }
                        else{
                            ct++;
                            ans=max(ans,ct);
                            break;
                        }
                        mp[num]=0;
                    }
                    else break;

                }
            }
        }
        return ans;
    }
};