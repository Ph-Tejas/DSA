class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return;
        int i=0,j=1;
        while(j<n){
            if(nums[i]==0){
                i++;
                while(j<=i)j++;
            }
            else{
                while(j<n&&nums[j]!=0){
                    j++;
                }
                if(j<n){
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
            }
        }
        j=i+1;
        while(j<n){
            if(nums[i]==1){
                i++;
                while(j<=i)j++;
            }
            else{
                while(j<n&&nums[j]!=1){
                    j++;
                }
                if(j<n){
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }

            }
        }
        

    }
};