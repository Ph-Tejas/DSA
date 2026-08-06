class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long n=nums.size();
        long long ans=1;
        long long i=0;
        long long tot=0;
        long long ct=1;
        sort(nums.begin(),nums.end());
        long long init=nums[0];
        for(long long j=1;j<n;j++){
            long long diff=nums[j]-nums[j-1];
            tot+=diff*ct;
            while(tot>k){
                tot-=nums[j]-nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            ct=j-i+1;

        }
        return ans;


    }
};