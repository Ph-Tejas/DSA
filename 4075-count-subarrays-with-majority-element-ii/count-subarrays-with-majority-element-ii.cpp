class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pf(n);
        pf[0]=(nums[0]==target)?1:-1;
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+((nums[i]==target)?1:-1);
        }
        long long ans=0;

        map<int,int>mp;
        mp[0]=1;
        vector<int>ind(n);
        if(pf[0]==1){
            ind[0]=1;
            mp[pf[0]]++;
            ans+=ind[0];
            // cout<<ans;
        }
        else{
            ind[0]=0;
            mp[pf[0]]++;
            ans+=ind[0];
            // cout<<ans;
        }
        for(int i=1;i<n;i++){
            if(pf[i]<pf[i-1]){
                ind[i]=ind[i-1]-mp[pf[i]];
                
            }
            else{
                ind[i]=ind[i-1]+mp[pf[i]-1];
                
            }
            mp[pf[i]]++;
            ans+=ind[i];
            // cout<<ans;
        }
        return ans;
    }
};  