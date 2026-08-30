class Solution {
public:
    vector<unordered_map<int,int>>v;
    int n;
    int dp[101][5001];
    int fun(int i,int sum){
        if(sum==0)return 0;
        if(i==n)return 1e9;
        if(dp[i][sum]!=-1)return dp[i][sum];

        int mini=INT_MAX;
        for(auto &val:v[i]){
            if(sum<val.first)continue;
            mini=min(mini,val.second+fun(i+1,sum-val.first));
        }
        return dp[i][sum]=mini;


    }
    int minOperations(vector<int>& nums, int sum) {
        n=nums.size();
        vector<int>twos={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int it=0;
            vector<pair<int,int>>sample;
            int id=nums[i];
            while(id!=0){
                mp[id]=it;
                if(id!=nums[i]){
                    if(mp.find(2*id)==mp.end()){
                        sample.push_back({id,it});
                    }
                }
                
                id/=2;
                it++;

            }
            id=nums[i];
            it=0;
            while(id<=sum){
                mp[id]=it;
                id*=2;
                it++;
            }
            mp[0]=0;
            int sz=sample.size();
            for(int l=0;l<sz;l++){
                int st=sample[l].second;
                int val=sample[l].first;

                while(val<=sum){
                    mp[val]=st;
                    val*=2;
                    st++;

                }

            }
            

            v.push_back(mp);
        }
        int ans=fun(0,sum);
        if(ans>=1e9)return -1;
        return ans;




    }
};