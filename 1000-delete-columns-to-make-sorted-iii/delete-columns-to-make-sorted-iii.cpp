class Solution {
public:
    map<pair<vector<int>,int>,int>mp;
    int n,m;
    int fun(int i,vector<int>prev,vector<string>& strs){
        if(i>m){
            return 0;
        }
        pair<vector<int>,int>prev_={prev,i};
        if(mp.find(prev_)!=mp.end()){
            return mp[prev_];
        }
        bool flag=true;
        vector<int>prevN=prev;
        int comp=fun(i+1,prevN,strs);
        for(int j=0;j<n;j++){
            int c=strs[j][i];
            if((c-'a')<prev[j]){
                flag=false;
                break;
            }
            prev[j]=(c-'a');


        }
        if(!flag)return mp[prev_]=comp;
        return mp[prev_]=max(comp,1+fun(i+1,prev,strs));



    }
    int minDeletionSize(vector<string>& strs) {
        n=strs.size();
        m=strs[0].size();
        vector<int>prev(n,-1);
        return m-fun(0,prev,strs);





    }
};