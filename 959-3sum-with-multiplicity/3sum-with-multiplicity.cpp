class Solution {
public:
    int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        unordered_map<int,int>mp;
        
        unordered_map<int,int>pr;
        int it1=-1,it2=-1;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            pr[arr[i]]=i;
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i];
                int b=arr[j];
                if(a+b>target)break;
                int c=target-a-b;
                if(c<b)break;
                ans+= min((max(pr[c]-j,0)),mp[c]);
                ans%=mod;

            }
        }
        return ans;
    }
};