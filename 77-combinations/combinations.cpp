class Solution {
public:
    vector<vector<int>>ans;
    int n,k;
    void fun(int i,vector<int>&l){
        if(l.size()==k){
            ans.push_back(l);
            return;
        }
        for(int it=i;it<=n;it++){
            if(n-it+2+l.size()<k)continue;
            l.push_back(it);
            fun(it+1,l);
            l.pop_back();
        }
        
        
        

    }
    vector<vector<int>> combine(int n_, int k_) {
        n=n_;
        k=k_;
        // for(int i=1;i<=n;i++){
        //     vector<int>v={i};
        vector<int>v;
            fun(1,v);
        // }
        return ans;
        
    }
};