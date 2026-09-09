class Solution {
public:
    long long countCommas(long long n) {
        string s=to_string(n);


        vector<long long>v={999,999999,999999999,999999999999,999999999999999};
        int ct=-1;
        for(int i=0;i<5;i++){
            if(v[i]<n){
                ct=i;
            }
        }
        if(ct==-1)return 0;
        long long ans=0;
        for(int i=0;i<=ct;i++){
            ans+=n-v[i];
        }
        return ans;


    }
};