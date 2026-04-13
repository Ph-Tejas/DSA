class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=start;i<n;i++){
            if(nums[i]==target){
                ans=min(ans,i-start);
            }
        }
        for(int i=start-1;i>-1;i--){
            if(nums[i]==target){
                ans=min(ans,start-i);
            }
        }
        return ans;
    }
};