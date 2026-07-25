class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=nums.size();
        int ct=count(nums.begin(),nums.end(),0);
        int x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
        }
        if(x==0)return true;
       
        if(nums.size()&1){
            return false;
        }
        return true;
    
       
    }
};