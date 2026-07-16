class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int ct=1;
        int maxi=nums[0];
        int mini=1e9;
        int mi=0;
        while(ct<n && nums[ct]==nums[ct-1]){
            ct++;
            mi++;
        }
        int ma=n-1;

        
        while(ma>=mi){
            if(ma-mi==0)break;
            if(ma-mi==1)break;
            int mid=mi+(ma-mi)/2;
            

            if(nums[mid]<maxi){
                mini=min(mini,nums[mid]);
                ma=mid;
            }
            else if(nums[mid]>maxi){
                maxi=max(maxi,nums[mid]);
                mi=mid;
            }
            else{
                if(nums[mid]<=nums[n-1]){
                    ma=mid;

                }
                else mi=mid;
            }

        }

        return min({nums[0],nums[mi],nums[ma]});
    }
};