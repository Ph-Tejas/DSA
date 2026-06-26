class MinStack {
public:
    stack<pair<int,int>>st;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        mini=min(mini,value);
        st.push({value,mini});
    }
    
    void pop() {
        st.pop();
        if(!st.empty())mini=st.top().second;
        else  mini=INT_MAX; 
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */