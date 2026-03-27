class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n-k+1);
        map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        auto it=mp.end();
        it--;
        ans[0]=(*it).first;
        for(int i=k;i<n;i++){
            int prev=nums[i-k];
            mp[prev]--;
            if(mp[prev]==0)mp.erase(prev);
            mp[nums[i]]++;
            it=mp.end();
            it--;
            ans[i-k+1]=(*it).first;
        }
        return ans;
    }
};