class Fancy {
public:
    vector<int>seq;
    long long mod=1e9+7;
    long long given;
    long long mul;
    Fancy() {
        given=0;
        mul=1;
    }
    long long modPow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
    long long modularAr(int val){
        return modPow(val,mod-2);
    }
    
    void append(int val) {
        long long vall=val;
        vall=(((vall-given+mod)%mod)*modularAr(mul))%mod;
        
        seq.push_back(vall);
    }
    
    void addAll(int inc) {
        given+=inc;
        given%=mod;

        
    }
    
    void multAll(int m) {
        mul*=m;
        mul%=mod;
        given*=m;
        given%=mod;


        
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size())return -1;
        long long a=seq[idx];
        a*=mul;
        a%=mod;
        return (a+given)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */