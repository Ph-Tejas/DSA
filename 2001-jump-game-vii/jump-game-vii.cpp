class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        int n=s.size();
        if(s.back()=='1')return false;
        vector<bool>result(n);
        vector<int>loc(n);
        int nxt=n-1;
        for(int i=n-2;i>-1;i--){
            if(s[i]=='1'){
                loc[i]=nxt;

            }
            else{
                loc[i]=nxt;
                nxt=i;
            }
        }
        stack<int>q;
        result[n-1]=true;
        q.push(n-1);
        while(!q.empty()){
            int ind=q.top();
            q.pop();
            if(ind==0)return true;
            for(int i=max(0,ind-mx);i<=ind-mn;i++){
                if(s[i]=='1'){
                    i=loc[i]-1;
                    continue;
                }
                if(result[i]==true)break;
                result[i]=true;
                q.push(i);
            }
        }
        return false;

    }
};