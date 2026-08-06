class Solution {
public:
    int n,sz;
    int fun(vector<pair<int,int>>v,vector<string>& strs,int it){
        if(it==sz)return 0;
        int l=v.size();
        bool flag=true;
        for(int i=0;i<l;i++){
            int a=v[i].first;
            int b=v[i].second;
            for(int j=a+1;j<=b;j++){
                if(strs[j][it]<strs[j-1][it]){
                    flag=false;
                }
            }


        
        }
        if(flag){
            cout<<it<<" ";

            vector<pair<int,int>>v1;

            for(auto &val:v){
                int a=val.first;
                int b=val.second;

                int itt=a;

            
                for(int i=a+1;i<=b;i++){
                    if(strs[i][it]!=strs[i-1][it]){
                        v1.push_back({itt,i-1});
                        itt=i;

                    }

                }
                v1.push_back({itt,b});
            }


            return 1+fun(v1,strs,it+1);


        }
        return fun(v,strs,it+1);

    }
    int minDeletionSize(vector<string>& strs) {
        n=strs.size();
        sz=strs[0].size();
        
        vector<pair<int,int>>v;
        v.push_back({0,n-1});
        int ct=0;
        return sz-fun(v,strs,0);






    }
};