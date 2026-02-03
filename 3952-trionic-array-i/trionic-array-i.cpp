class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(nums[1]<=nums[0])return false;
        if(nums[n-2]>=nums[n-1])return false;
        int ct1=0,ct2=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]<nums[i+1]&&nums[i+1]>nums[i+2])ct1++;
        }
        for(int i=0;i<n-2;i++){
            if(nums[i]>nums[i+1]&&nums[i+1]<nums[i+2])ct2++;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])return false;
        }
        if(ct1==ct2&&ct2==1)return true;
        return false;
        
    }
};