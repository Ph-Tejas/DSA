class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]++;
        nums[0]%=k;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
            nums[i]%=k;
            if(mp[nums[i]]>=1)return true;
            mp[nums[i-1]]++;


        }
        return false;

    }
};