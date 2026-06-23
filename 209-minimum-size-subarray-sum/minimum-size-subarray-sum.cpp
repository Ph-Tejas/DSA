class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int ct=1e9;
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            
            while(sum>=target){
                ct=min(ct,j-i+1);
                sum-=nums[i];
                i++;

            }
            

        }
        return (ct==1e9)?0:ct;
    }
};