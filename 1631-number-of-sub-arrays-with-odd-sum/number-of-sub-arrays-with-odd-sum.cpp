class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int h=0;
        int freq[2]={1,0};
        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            h+=arr[i];
            h=(h&1);
            ans+=freq[!h];
            ans%=mod;
            freq[h]++;
        }
        return ans;



    }
};