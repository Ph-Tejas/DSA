class FreqStack {
public:
    int timer;
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>mp;

    FreqStack() {
        timer=0;
        
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],{timer,val}});        
        timer++;
    }
    
    int pop() {
        int val=pq.top().second.second;
        pq.pop();
        mp[val]--;
        return val;
    }
};
