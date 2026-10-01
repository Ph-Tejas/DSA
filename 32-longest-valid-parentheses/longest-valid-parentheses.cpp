class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        map<int,int>mp;
        vector<int>v(n+1);
        int ans=0;
        int ct=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ct++;

            }
            else{
                ct--;
                if(mp.find(ct)!=mp.end()){
                    v[mp[ct]+1]+=1;
                    v[i+1]-=1;

                }
            }
            
            mp[ct]=i;
        }
        int h=0;
        int maxi=0;
        for(int i=0;i<=n;i++){
            h+=v[i];
            v[i]=h;
            cout<<v[i]<<" ";
            maxi=max(maxi,h);

        }
        for(int i=0;i<=n;i++){
            if(v[i]>0){
                int ct=0;
                while(i<=n && v[i]>0){
                    i++;
                    ct++;
                }
                ans=max(ans,ct);
                


            }
        }
        return ans;
        return maxi;

    }
};