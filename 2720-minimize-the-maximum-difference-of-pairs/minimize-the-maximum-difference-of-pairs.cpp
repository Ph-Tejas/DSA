class Solution {
public:
    vector<vector<int>>dp;
    
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<n-1;i++){
            v.push_back(nums[i+1]-nums[i]);
        }
        int mini=0;
        int maxi=1e9;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            int p_=p;
            vector<int>vis(n-1);
            for(int i=0;i<n-1;i++){
                if(vis[i])continue;
                if(v[i]<=mid){
                    if(i!=n-2)vis[i+1]=true;
                    p_--;
                }

            }
            if(p_<=0){
                maxi=mid-1;
            }
            else mini=mid+1;



        }
        return mini;

        

    }
};