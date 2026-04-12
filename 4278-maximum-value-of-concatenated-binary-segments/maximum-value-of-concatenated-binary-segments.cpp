class Solution {
public:
    int mod=1e9+7;
    long long powy(long long a,long long p){
        a%=mod;
        if(p==0){
            return 1;
        }
        if(p==1){
            return a;
        }
        
        if(p&1){
            return (a*powy(a*a,(p>>1)))%mod;
        }
        else{
            return powy(a*a,(p>>1))%mod;
        }
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n=nums1.size();
        int ct=0;
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++){
            if(nums0[i]==0){
                ct+=nums1[i];
                nums1[i]=0;
                continue;
                

            }
            pr.push_back({nums1[i],nums0[i]});
        }

        sort(pr.begin(),pr.end(),[](pair<int,int>&pr1,pair<int,int>&pr2){
            if(pr1.first==pr2.first){
                return pr1.second<pr2.second;
            }
            return pr1.first>pr2.first;
        });
        n=pr.size();
        vector<int>fin;
        for(int i=0;i<ct;i++)fin.push_back(1);
        for(int i=0;i<n;i++){
            
            for(int j=0;j<pr[i].first;j++){
                fin.push_back(1);
            }
            for(int j=0;j<pr[i].second;j++){
                fin.push_back(0);
            }
        }
        int sz=fin.size();
        long long ans=0;
        vector<long long> pow2(sz);
pow2[0] = 1;
for(int i = 1; i < sz; i++){
    pow2[i] = (pow2[i-1] * 2) % mod;
}
        for(int i=0;i<sz;i++){
            if(fin[i]==1){
                ans += pow2[sz-1-i];
                ans%=mod;
            }
        }
        return ans;


    }
};