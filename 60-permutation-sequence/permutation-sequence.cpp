class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>store(n+1,1);
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            store[i]=store[i-1]*i;
        }
        string ans;
        int sz=n;
        
        
            
            while(sz>0){
                int ct=0;
                for(int i=1;i<=n;i++){
                    if(vis[i])continue;
                    ct++;
                    if(k<=(ct)*store[sz-1]){
                        k-=(ct-1)*store[sz-1];
                        ans.push_back('0'+(i));
                        sz--;
                        vis[i]=1;
                        break;
                    }
                }

            }

            
    
        return ans;

    }
};