class Solution {
public:
    int mod=1e9+7;
long long binPow(long long a, long long p){
    long long res = 1;
    while(p){
        if(p & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return res;
}
    int multInv(int n){
        return binPow(n,mod-2)%mod;
    }

    int countVisiblePeople(int n, int pos, int k) {
        long long X=pos;
        long long N_X=n-X-1;
        vector<long long>x(k+1,1);
        vector<long long>n_x(k+1,1);
        for(int i=1;i<=k;i++){
            if(i>X)break;
            x[i]=x[i-1]*(X-i+1);
            x[i]%=mod;
            x[i]*=multInv(i);
            x[i]%=mod;


        }
        for(int i=1;i<=k;i++){
            if(i>N_X)break;
            n_x[i]=n_x[i-1]*(N_X-i+1);
            n_x[i]%=mod;
            n_x[i]*=multInv(i);
            n_x[i]%=mod;


        }
        long long ans=0;
        if(pos==0){
            return (n_x[k]*2)%mod;
        }
        if(pos==n-1){
            return (x[k]*2)%mod;
        }
        else{
            for(int i=0;i<=k;i++){
                if(k-i>N_X)continue;
                if(i>X)continue;
                ans+=((x[i]*n_x[k-i])%mod);
                ans%=mod;
            }
        }
        return (ans*2)%mod;
        

    }
};