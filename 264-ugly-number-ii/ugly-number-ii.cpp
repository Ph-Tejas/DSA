class Solution {
public:
    int nthUglyNumber(int n) {
        set<int>st;
        vector<int>power2={1};
        vector<int>power3={1};
        vector<int>power5={1};
        st.insert(1);
        long long a=1;
        long long b=1;
        long long c=1;
        bool flag1=false;
        bool flag2=false;
        bool flag3=false;
        
        for(int i=1;i<32;i++){
            if(!flag1)a*=2;
            if(!flag2)b*=3;
            if(!flag3)c*=5;
            if(a<=INT_MAX*1LL)power2.push_back(a);
            else flag1=true;
            if(b<=INT_MAX*1LL)power3.push_back(b);
            else flag2=true;
            if(c<=INT_MAX*1LL)power5.push_back(c);
            else flag3=true;
        }
        for(int i=0;i<power2.size();i++){
            long long num=power2[i];
            for(int j=0;j<power3.size();j++){
                num*=power3[j]; 
                if(num<=INT_MAX*1LL){    
                    
                    for(int k=0;k<power5.size();k++){
                        num*=power5[k];
                        if(num<=INT_MAX*1LL){
                            st.insert(num);
                        }
                        num/=power5[k];
                    }
                }
                num/=power3[j];
            }
        }
        int it=0;
        for(auto &val:st){
            it++;
            if(it==n)return val;
        }
        return 0;





    }
};