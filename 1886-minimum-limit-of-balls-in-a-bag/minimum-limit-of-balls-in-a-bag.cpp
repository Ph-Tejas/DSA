class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int mini=1;
        int maxi=INT_MAX;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            int ct=0;
            for(int i=0;i<n;i++){
                ct+=nums[i]/mid;
                if(nums[i]%mid==0)ct--;
            }

            if(ct > maxOperations){
                mini=mid+1;
            }
            else maxi=mid-1;



        }
        return mini;
        
    }
};