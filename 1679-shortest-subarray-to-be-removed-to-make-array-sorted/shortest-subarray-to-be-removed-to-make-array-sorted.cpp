class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        vector<int>v1;
        vector<int>v2;
        v1.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>=v1[i-1])v1.push_back(arr[i]);
            else break;
        }   
        v2.push_back(arr[n-1]);
        for(int i=n-2;i>-1;i--){
            if(arr[i]<=v2.back())v2.push_back(arr[i]);
            else break;
        }
        reverse(v2.begin(),v2.end());
        int mini=min(n-v1.size(),n-v2.size());
        int sz1=v1.size();
        int sz2=v2.size();
        if(sz1==n)return 0;
        for(int i=0;i<sz1;i++){
            int curr=v1[i];
            int it=lower_bound(v2.begin(),v2.end(),curr)-v2.begin();
            mini=min(mini,n-(i+1)-(sz2-it));
        }
        return mini;
        
        
    }
};