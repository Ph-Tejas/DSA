class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n);
        dp[n-1]=nums[n-1];
        int j=n-1;
        map<int,int>mp;
        mp[nums[n-1]]++;
        for(int i=n-2;i>-1;i--){
            auto it=mp.end();
            --it;
            int val=(*it).first;
            int curr=val+nums[i];
            if(j-i==k){
                mp[dp[j]]--;
                if(mp[dp[j]]==0)mp.erase(dp[j]);
                j--;
            }
            mp[curr]++;
            dp[i]=curr;
        }
        return dp[0];
    }
};