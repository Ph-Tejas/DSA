class RideSharingSystem {
public:
    queue<int>qr,qd;
    set<int>av;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        qr.push(riderId);
        av.insert(riderId);
    }
    
    void addDriver(int driverId) {
        qd.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(qd.empty())return {-1,-1};
        while((!qr.empty())&&av.find(qr.front())==av.end()){
            qr.pop();
        }
        if(qr.empty())return{-1,-1};
        vector<int>ans= {qd.front(),qr.front()};
        qd.pop();
        qr.pop();
        return ans;
    }
    
    void cancelRider(int riderId) {
        if(av.find(riderId)!=av.end()){
            av.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */