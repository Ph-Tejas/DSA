class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        vector<map<int,int>>adj(n);
        int ans=2;
        for(int i=0;i<n-1;i++){
            adj[i][nums[n-1]-nums[i]]=2;
        }
        for(int i=n-2;i>-1;i--){
            for(int j=i-1;j>-1;j--){
                if(adj[i].find(nums[i]-nums[j])!=adj[i].end()){
                    adj[j][nums[i]-nums[j]]=adj[i][nums[i]-nums[j]]+1;
                }
                else{
                    adj[j][nums[i]-nums[j]]=2;
                }
                ans=max(ans,adj[j][nums[i]-nums[j]]);
            }
        }
        
        return ans;
    }
};