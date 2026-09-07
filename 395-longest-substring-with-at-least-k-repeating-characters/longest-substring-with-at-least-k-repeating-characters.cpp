class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        vector<vector<int>>v(n,vector<int>(26));
        v[0][s[0]-'a']++;
        for(int i=1;i<n;i++){
            v[i]=v[i-1];
            v[i][s[i]-'a']++;
        }
        int ans=0;
        vector<int>l(26,-1);
        for(int i=0;i<n;i++){
            l[s[i]-'a']=i;
            bool f=true;
            for(int a=0;a<26;a++){
                if(v[i][a]<k){
                    f=false;
                }
            }
            if(f){
                ans=i+1;
                continue;
            }
            for(int a=0;a<26;a++){
                bool flag=true;
                
                
                for(int j=0;j<26;j++){
                    if(l[a]!=-1 && v[i][j]-v[l[a]][j]!=0 && v[i][j]-v[l[a]][j]<k){
                        flag=false;
                    }
                    if(l[a]==-1 && v[i][j]!=0 && v[i][j]<k){
                        flag=false;
                    }
                }
                
                if(flag)ans=max(ans,i-l[a]);
            }
        }
        return ans;

    }
};