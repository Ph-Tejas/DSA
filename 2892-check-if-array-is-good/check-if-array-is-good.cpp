class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        auto it=mp.end();
        it--;
        if(mp.size()==n-1&&(*it).first==n-1&&(*it).second==2)return true;
        return false;
    }
};