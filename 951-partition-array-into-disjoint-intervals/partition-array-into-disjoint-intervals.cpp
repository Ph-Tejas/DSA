class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>fwd(n);
        fwd[0]=nums[0];
        for(int i=1;i<n;i++){
            fwd[i]=max(fwd[i-1],nums[i]);
        }
        vector<int>bck(n);
        bck[n-1]=nums[n-1];
        for(int i=n-2;i>-1;i--){
            bck[i]=min(bck[i+1],nums[i]);
        }

        for(int i=0;i<n-1;i++){

            if(fwd[i]<=bck[i+1]){
                return i+1;
            }
        }
        return n;
    }
};