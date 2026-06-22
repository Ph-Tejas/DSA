class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ct=1;
        int ele=nums[0];
        int ans=1;
        int it1=0;
        int it2=0;
        bool flag=false;
        for(int i=1;i<n;i++){
            if(nums[i]<ele)break;
            if(ele==nums[i]){
                if(ct==1){
                    if(flag){
                        swap(nums[it1],nums[i]);
                        it1++;
                    }
                    ct++;
                    ans++;
                }
                else{
                    if(!flag){
                        it1=i;
                        flag=true;
                    }

                }
            }
            else{
                ct=1;
                ele=nums[i];
                if(flag){
                    swap(nums[it1],nums[i]);
                    it1++;
                }
                ans++;
            }
        }
        return ans;
    }
};