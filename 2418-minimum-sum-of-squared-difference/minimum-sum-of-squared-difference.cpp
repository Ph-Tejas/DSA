class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int>diff;
        for(int i=0;i<n;i++){
            diff.push_back(abs(nums1[i]-nums2[i]));
        }
        sort(diff.begin(),diff.end());
        reverse(diff.begin(),diff.end());
        
        int tot=k1+k2;
        int mini=0;
        int maxi=1e5;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            long long req=0;
            for(int i=0;i<n;i++){
                if(diff[i]>mid){
                    req+=diff[i]-mid;
                }
            }
            if(req<=tot){
                maxi=mid-1;
            }
            else mini=mid+1;
        }
        for(int i=0;i<n;i++){
            if(diff[i]>mini){

                tot-=diff[i]-mini;
                diff[i]=mini;
            }
        }
        if(mini==0)return 0;
        int it=0;
        while(tot--){
            diff[it]--;
            it++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=((long long)diff[i]*diff[i]);
        }
        return ans;




    }
};