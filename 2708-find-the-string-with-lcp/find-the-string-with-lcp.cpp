class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr=lcp[i][j];
                if(i==j){
                    if(curr!=n-i)return "";
                }
                else{
                    if(curr!=lcp[j][i])return "";
                }
            }
        }
        string ans(n,'.');
        ans[n-1]='z';
        for(int i=n-2;i>-1;i--){
            vector<int>vis(26);
            bool flag=true;
            bool done=false;
            for(int j=i+1;j<n;j++){
                int curr=lcp[i][j];
                if(curr==0){
                    if(vis[ans[j]-'a']==2)return "";
                    vis[ans[j]-'a']=1;

                }
                else{
                    if(vis[ans[j]-'a']==1)return "";
                    if(flag){
                        flag=false;
                        vis[ans[j]-'a']=2;
                        ans[i]=ans[j];
                        done=true;
                        if(lcp[i][j]>n-j){
                            return "";
                        }
                        if(j+1<n){
                            if(lcp[i+1][j+1]!=curr-1){
                                return "";
                            }
                        }
                    }
                    else{
                        if(vis[ans[j]-'a']!=2){
                            return "";
                        }
                        if(j+1<n){
                            if(lcp[i+1][j+1]!=curr-1){
                                return "";
                            }
                        }


                    }
                }
            }
            if(!done){
                for(int j=25;j>-1;j--){
                    if(vis[j]==0){
                        ans[i]=('a'+j);
                        done=true;
                        break;
                    }
                }
            }
            if(!done)return "";
        }
        char it='a';
        map<char,char>mp;
        
        for(int i=0;i<n;i++){
            if(mp.find(ans[i])!=mp.end()){
                ans[i]=mp[ans[i]];
            }
            else{
                mp[ans[i]]=it;
                ans[i]=it;
                it++;
            }
        }
        return ans;
        

    }
};