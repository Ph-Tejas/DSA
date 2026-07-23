class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int ct=0;
        if(n==1)return 1;
        if(n==2)return 2;
        int ans=0;
        while(n>0){
            ans++;
            n/=2;
        }
        return pow(2,ans);
    }
};