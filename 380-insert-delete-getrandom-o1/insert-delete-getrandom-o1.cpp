class RandomizedSet {
public:
    vector<int>v;
    int i=0;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    
    bool insert(int val) {
        bool flag=true;
        if(mp.find(val)!=mp.end()){
            flag=false;
        }
        else{
            v.push_back(val);
            mp[val]=v.size()-1;
            
        }
        return flag;
    }
    
    bool remove(int val) {
        bool flag=false;
        
        if(mp.find(val)!=mp.end()){
            flag=true;
            swap(v[mp[val]],v[v.size()-1]);
            mp[v[mp[val]]]=mp[val];
            mp.erase(v[v.size()-1]);
            v.pop_back();
        }
        
        
        return flag;
    }
    
    int getRandom() {
        int i=rand()%v.size();
        return v[i];


    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */