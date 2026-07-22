class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();


        for(int i=0;i<n;i++){
            nums[i]=(nums[i]+k*100000)%k;
        }
        map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
            prev+=nums[i];
            prev%=k;
            ans+=mp[prev];
            
            cout<<i<<" "<<ans<<endl;
            mp[prev]++;
        }
        return ans;



    }
};