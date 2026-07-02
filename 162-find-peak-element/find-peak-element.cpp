class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;

        int mini=0;
        int maxi=n-1;
        int mid;
        while(maxi>=mini){
            mid=mini+(maxi-mini)/2;
            if(mid==0){

                if(nums[mid]>nums[1])return mid;
                else {
                    mini=mid+1;
                }
                continue;
            
            }
            else if(mid==n-1){
                if(nums[mid]>nums[n-2])return mid;
                else maxi=mid-1;
                continue;
                
            }
            else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                return mid;
            }
            if(nums[mid]>nums[mid-1]&&nums[mid+1]>nums[mid]){
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }

        }
        
    
        return mini;






    }
};