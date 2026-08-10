struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:

    unordered_map<pair<int,int>,int,PairHash>mp;
    int maxx;
    int t;
    bool fun(int vis,int T){
        if(T<=0)return false;

        if(mp.find({vis,T})!=mp.end())return mp[{vis,T}];

        bool ans=false;
        for(int i=0;i<maxx;i++){
            if((vis>>i)&1)continue;
            int newVis=(vis|(1<<i));
            ans=(ans|(!fun(newVis,T-(i+1))));
            if(ans)break;
        }
        return mp[{vis,T}]=ans;

    }

    bool canIWin(int mx, int total) {
        maxx=mx;
        if((mx*(mx+1))/2<total)return false;
        
        t=total;
        if(t==0)return true;
        return fun(0,total);
    }
};