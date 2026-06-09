class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int num=nums[0];
        int mini=0;
        int maxi=n-1;
        int mid=mini+(maxi-mini)/2;
        while(maxi>=mini){  
            if(nums[mid]<num){
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }


            mid=mini+(maxi-mini)/2;
        }
        return nums[mini%n];
    }
};