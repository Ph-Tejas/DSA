class ProductOfNumbers {
public:
    vector<int>st;
    vector<int>zeros;
    ProductOfNumbers() {
        st.push_back(1);
        zeros.push_back(0);
        
    }
    
    void add(int num) {

        if(st.back()!=0)st.push_back(st.back()*num);
        else st.push_back(num);
        if(num==0){
            zeros.push_back(zeros.back()+1);
        }
        else zeros.push_back(zeros.back());

        

    }
    
    int getProduct(int k) {
        int n=st.size();

        if(zeros.back()-zeros[n-k-1]==0){
            if(st[n-k-1]==0)return st.back();
            return st.back()/st[n-k-1];
        }
        return 0;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */