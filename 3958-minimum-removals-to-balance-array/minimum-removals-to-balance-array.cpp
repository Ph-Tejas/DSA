class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<=n-1;i++){
            long long num=nums[i];
            int mini=0;
            int maxi=n-1-i;
            int mid=mini+(maxi-mini)/2;
            while(maxi>=mini){
                bool com=false;
                if(num*(long long)k>=(long long)nums[n-1-mid])com=true;
                if(com)maxi=mid-1;
                else mini=mid+1;
                mid=mini+(maxi-mini)/2;
            }
            ans=min(ans,mini+i);


        }
        return ans;
    }
};