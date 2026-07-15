class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>st;
        vector<pair<int,int>>v;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(st.empty())continue;
                v.push_back({st.top(),i});
                st.pop();
            }
        }

        sort(v.begin(),v.end());
        
        int sz=v.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<sz;i++){
            if(i==0)vp.push_back(v[i]);
            else{
                if(v[i].first-vp.back().second>0)vp.push_back(v[i]);
            }
        }
        sz=vp.size();
        if(sz==0)return 0;
        int ans=vp[0].second-vp[0].first+1;
        int ct=ans;
        for(int i=1;i<sz;i++){
            if(vp[i].first-vp[i-1].second==1){
                ct+=vp[i].second-vp[i].first+1;

            }
            else{
                ct=vp[i].second-vp[i].first+1;
                
            }

            ans=max(ans,ct);
        }
        return ans;
    }
};