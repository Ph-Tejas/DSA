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
            for(int i=0;i<n-1;i++){
                
                if(v[i]<=mid){
                    p_--;
                    i++;
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