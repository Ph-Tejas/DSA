class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        int ct=0;   
        for(int i=0;i<2*n-1;i++){
            if(nums[i]<=nums[i+1])ct++;
            else{
                ct=0;
            }
            if(ct>=n-1)return true;

        }
        return false;
    }
};