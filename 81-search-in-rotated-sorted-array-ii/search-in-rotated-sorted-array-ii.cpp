class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int a=nums[0];
        if(a==target)return true;
        while(!nums.empty()&&nums.back()==a){
            nums.pop_back();
        }
        int n=nums.size();
        if(n==0)return false;
        int mini=0;
        int maxi=n-1;
        int mid=mini+(maxi-mini)/2;
        while(maxi>=mini){
            if(nums[mid]==target)return true;
            if(nums[mid]<a){
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
            mid=mini+(maxi-mini)/2;
        }
        if(mini==n){
            mini=0;
            maxi=n-1;
            if(nums[n-1]<target)return false;
        }
        else{
            if(target>a){
                maxi=mini-1;
                mini=0;
            }
            else{
                maxi=n-1;
            }
        }
        auto ans=lower_bound(nums.begin()+mini,nums.begin()+maxi+1,target);
        if(ans==nums.begin()+maxi+1)return false;
        if((*ans)==target)return true;
        return false;
        
    }
};