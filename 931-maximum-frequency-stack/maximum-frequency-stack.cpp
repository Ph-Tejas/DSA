class FreqStack {
public:
    int timer;
    priority_queue<vector<int>>pq;
    map<int,int>mp;

    FreqStack() {
        timer=0;
        
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],timer,val});        
        timer++;
    }
    
    int pop() {
        int val=pq.top()[2];
        pq.pop();
        mp[val]--;
        return val;
    }
};
