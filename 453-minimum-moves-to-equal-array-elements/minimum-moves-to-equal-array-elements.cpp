class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        
        int ans=0;
        int prev=0;
        for(int i=0;i<n-1;i++){
            
            int diff=nums[i+1]+prev-nums[i];

            ans+=diff;
            prev=diff;
        }
        return ans;



    }
};