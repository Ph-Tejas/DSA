class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        while(nums2.size()<n){
            nums2.push_back(-1);
        }
        int ct=nums2.size()-n;
        reverse(nums1.begin(),nums1.end());
        reverse(nums2.begin(),nums2.end());

        int ans=0;
        for(int i=0;i<n;i++){
            int it=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            if(it-ct>=i)continue;
            ans=max(ans,i-(it-ct));


        }
        return ans;
        
    }
};