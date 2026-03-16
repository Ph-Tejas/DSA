class Fancy {
public:
    vector<int>seq;
    long long mod=1e9+7;
    long long given;
    long long mul;
    vector<long long>powy;
    Fancy() {
        powy.resize(50,1);
        given=0;
        mul=1;
    }
    void binaryPow(int val){
        long long system=val;
        for(int i=0;i<50;i++){
            
            powy[i]=system;
            system*=system;
            system%=mod;
        }
    }
    long long modularAr(int val){
        long long ref=1e9+5;
        long long sumMul=1;
        binaryPow(val);

        for(int i=0;i<50;i++){
            if((ref>>i)&1){
                sumMul*=powy[i];
                sumMul%=mod;

            }
        }
        return sumMul;
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