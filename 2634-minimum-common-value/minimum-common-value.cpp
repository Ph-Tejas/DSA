class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int it1=0;
        int it2=0;
        while(it1<nums1.size()&&it2<nums2.size()){
            if(nums1[it1]==nums2[it2]){
                return nums1[it1];
            }
            else if(nums1[it1]<nums2[it2]){
                it1++;
            }
            else{
                it2++;
            }
        }
        return -1;
    }
};