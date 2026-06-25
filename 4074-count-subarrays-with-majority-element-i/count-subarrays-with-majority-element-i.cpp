class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pf(n);
        pf[0]=((nums[0]==target)?1:0);
        for(int j=1;j<n;j++){
            pf[j]=pf[j-1]+((nums[j]==target)?1:0);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            
            for(int j=-1;j<i;j++){
                if(j==-1){
                    if(pf[i]>(i+1)/2){
                        ans++;
                    }
                }
                else{
                    if(pf[i]-pf[j]>(i-j)/2){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};