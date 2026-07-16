class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=-1;
        vector<int>pf;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            pf.push_back(gcd(nums[i],mx));





        }
        long long sum=0;
        sort(pf.begin(),pf.end());
        for(int i=0;i<n/2;i++){
            sum+=gcd(pf[i],pf[n-1-i]);
        }
        return sum;

    }
};