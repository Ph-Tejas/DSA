class Solution {
public:
    set<vector<int>>ans;
    vector<int>v;
    vector<bool>vis;
    void fun(int n,int k){
        if(n==0 &&k==0){
            vector<int>temp=v;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(k==0)return ;
        for(int i=1;i<=9;i++){
            if(vis[i])continue;
            if(i>n)break;
            vis[i]=true;
            v.push_back(i);
            fun(n-i,k-1);
            vis[i]=false;
            v.pop_back();
            

        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vis.resize(10);
        fun(n,k);
        vector<vector<int>>fin;
        for(auto &val:ans){
            fin.push_back(val);
        }
        return fin;
    }
};