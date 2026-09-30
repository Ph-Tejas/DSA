class Solution {
public:
    void fun(int a,int b,vector<bool>&shouldNotTouch,int toCheck,string &seq){
        int ct=0;
        // cout<<a<<b;
        for(int i=a;i<=b;i++){
            if(seq[i]=='('){
                if(ct==toCheck){
                    continue;
                }
                ct++;
            }
            else {
                if(ct==0)continue;
                ct--;
            }
            shouldNotTouch[i]=false;
            
        }
        
    }
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        map<int,vector<pair<int,int>>>mp;
        int c=1;
        int ct=1;
        int st=0;
        
        for(int i=1;i<n;i++){
            if(seq[i]=='('){
                ct++;
            }
            else{
                ct--;
            }
            c=max(c,ct);
            if(ct==0){
                mp[c].push_back({st,i});
                st=i+1;
                c=0;
            }
        }
        auto mx=mp.end();
        mx--;
        int vMax=mx->first;

        vector<bool>shouldNotTouch(n);
        int toCheck=vMax/2;
        vector<pair<int,int>>pairs;
        for(auto &v1:mp){
            if(v1.first>toCheck){
                for(auto &val:mp[v1.first]){

                    for(int i=val.first;i<=val.second;i++){
                        shouldNotTouch[i]=true;
                    }
                    pairs.push_back(val);
                }
            }
        }

        if(vMax==1){
            vector<int>ans(n);
            return ans;


        }
        int sz=pairs.size();
        for(int i=0;i<sz;i++){
            int a=pairs[i].first;
            int b=pairs[i].second;
            // cout<<a<<" "<<b<<endl; 
            fun(a,b,shouldNotTouch,toCheck,seq);
        }
        vector<int>fin;
        for(int i=0;i<n;i++){
            if(shouldNotTouch[i]==false){
                fin.push_back(0);
            }
            else fin.push_back(1);
        }
        return fin;

    }
};