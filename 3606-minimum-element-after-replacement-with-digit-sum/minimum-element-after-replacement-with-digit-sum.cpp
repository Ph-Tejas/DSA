class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int c;
        int d;
        for(int i=0;i<n;i++){
            d=0;
            c=nums[i];
            ans=min(ans,c);
            d+=c%10;
            c/=10;
            d+=c%10;
            c/=10;
            d+=c%10;
            c/=10;
            d+=c%10;
            c/=10;
            d+=c%10;
            c/=10;
            
            ans=min(ans,d);
        }
        return ans;
    }
};