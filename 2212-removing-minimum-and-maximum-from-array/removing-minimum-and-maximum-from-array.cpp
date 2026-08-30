class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int it1=max_element(nums.begin(),nums.end())-nums.begin();
        int it2=min_element(nums.begin(),nums.end())-nums.begin();
        if(it1>it2)swap(it1,it2);
        return min({it1+1+(int)nums.size()-it2,it2+1,(int)nums.size()-it1});
        
    }
};