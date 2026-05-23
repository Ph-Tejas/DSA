class CustomStack {
public:
    int mx;
    int ct;
    vector<int>v;
    CustomStack(int maxSize) {
        mx=maxSize;
        ct=0;

    }
    
    void push(int x) {
        if(v.size()==mx)return ;
        v.push_back(x);
    }
    
    int pop() {
        if(v.empty())return -1;
        int l=v.back();
        v.pop_back();
        return l;

    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)v.size());i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */