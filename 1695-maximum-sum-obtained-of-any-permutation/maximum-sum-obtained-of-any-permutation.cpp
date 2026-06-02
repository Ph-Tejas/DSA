class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<long long>loc(n+1);

        int sz=requests.size();
        for(int i=0;i<sz;i++){
            loc[requests[i][0]]++;
            loc[requests[i][1]+1]--;
        }
        for(int i=1;i<n;i++){
            loc[i]+=loc[i-1];
        }

        loc.pop_back();
        sort(nums.begin(),nums.end(),[](int &a,int &b){
            return a>b;
        });
        sort(loc.begin(),loc.end(),[](long long &a,long long &b){
            return a>b;
        });

        long long ans=0;
        for(int i=0;i<n;i++){
            if(loc[i]==0)break;
            ans+=nums[i]*loc[i];
            ans%=((long long)(1e9+7));
        }
        return ans;
        







    }
};