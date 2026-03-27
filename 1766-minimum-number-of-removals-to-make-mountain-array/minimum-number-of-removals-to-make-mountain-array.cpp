class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>inc(n);
        vector<int>dec(n);

        for(int i=0;i<n;i++){
            int curr=nums[i];
            int ct=0;
            for(int j=0;j<=i;j++){
                if(j==i){
                    ct=max(ct,1);
                }
                else if(nums[j]<curr){
                    ct=max(ct,inc[j]+1);
                }
            }
            inc[i]=ct;
        }
        for(int i=n-1;i>-1;i--){
            int curr=nums[i];
            int ct=0;
            for(int j=n-1;j>=i;j--){
                if(j==i){
                    ct=max(ct,1);
                }
                else if(nums[j]<curr){
                    ct=max(ct,dec[j]+1);
                }
            }
            dec[i]=ct;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(inc[i]==1)continue;
            if(dec[i]==1)continue;
            ans=min(ans,n-inc[i]-dec[i]+1);
        }
        return ans;




    }
};