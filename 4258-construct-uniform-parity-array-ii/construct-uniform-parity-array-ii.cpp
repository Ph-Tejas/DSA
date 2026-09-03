class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0;i<n;i++){
            if(nums[i]&1)mp1[nums[i]]++;
            else mp2[nums[i]]++;
        }
        bool ans1=true,ans2=true;
        for(int i=0;i<n;i++){
            if((nums[i]&1)==0){
                if(mp1.upper_bound(nums[i]-1)==mp1.begin()){
                    ans1=false;
                }
            }
        }
        for(int i=0;i<n;i++){
            if((nums[i]&1)){
                if(mp1.upper_bound(nums[i]-1)==mp1.begin()){
                    ans2=false;
                }
            }
        }
        return (ans1||ans2);
    }
};