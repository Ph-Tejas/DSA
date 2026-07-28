class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>fwd(n,nums[0]);
        for(int i=1;i<n;i++){
            fwd[i]=min(fwd[i-1],nums[i]);
        }
        bool flag=false;
        priority_queue<int,vector<int>,greater<int>>pq;
        if(n<3)return false;
        // if(nums[n-2]<=fwd[n-3])return false;
        for(int i=n-2;i>0;i--){
            while(!pq.empty() && pq.top()<=fwd[i-1]){
                pq.pop();
            }
            if(fwd[i-1]<nums[i+1]){
                pq.push(nums[i+1]);

            }
            if(fwd[i-1]>=nums[i])continue;
            if(!pq.empty()){
                if(pq.top()<nums[i])flag=true;
            }

        }
        return flag;
        
    }
};