class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int it1=max_element(nums.begin(),nums.end())-nums.begin();
        int it2=min_element(nums.begin(),nums.end())-nums.begin();
        if(it1>it2)swap(it1,it2);
        int ans=min(it2+1,n-it1);
        return min(ans,it1+1+n-it2);
        
    }
};