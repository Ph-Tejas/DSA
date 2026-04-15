class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int>sample;
        int it=n-k;
        for(it;it<n;it++){
            sample.push_back(nums[it]);
        }
        it=0;
        for(it;it<n-k;it++){
            sample.push_back(nums[it]);
        }
        nums=sample;
        

    }
};