class Solution {
public:
    int ct=0;
    vector<int>p;
    void check(int a,int b,int (&vmp)[501][501],int &n,vector<vector<int>>& preferences){
        for(auto &val:preferences[a]){
            
            if(val==b)break;
            if(vmp[val][a]<vmp[val][p[val]]){
                ct++;
                break;
            }

        }
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int vmp[501][501];
        p.resize(n);

        int sz=pairs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                vmp[i][preferences[i][j]]=j;
            }
        }
        for(int i=0;i<sz;i++){
            int a=pairs[i][0];
            int b=pairs[i][1];
            p[a]=b;
            p[b]=a;
        }
        for(int i=0;i<sz;i++){
            int a=pairs[i][0];
            int b=pairs[i][1];
            check(a,b,vmp,n,preferences);
            check(b,a,vmp,n,preferences);
            
        }
        return ct;



    }
};