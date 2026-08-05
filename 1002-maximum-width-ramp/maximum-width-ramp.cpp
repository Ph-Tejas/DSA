class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(1e5+1,-1);
        vector<int>v2(1e5+1,-1);
        for(int i=0;i<n;i++){
            if(v[nums[i]]==-1)v[nums[i]]=i;
            v2[nums[i]]=i;
        }
        vector<int>v1(1e5+1,-1);
        int maxi=-1;
        for(int i=1e5-1;i>-1;i--){
            maxi=max(maxi,v2[i]);
            v1[i]=maxi;
        }
        if(v1[0]==-1)return 0;
        int ans=0;

        for(int i=0;i<n;i++){
            // cout<<v1[i]<<" ";
            int curr=nums[i];
            ans=max(v1[nums[i]]-i,ans);
        }
        return ans;

    }
};