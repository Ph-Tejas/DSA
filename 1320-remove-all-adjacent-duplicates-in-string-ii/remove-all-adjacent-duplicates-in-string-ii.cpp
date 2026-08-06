class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty()){
                char ch=st.top().first;
                int f=st.top().second;
                if(ch==s[i]){
                    f+=1;
                    st.pop();
                    st.push({ch,f});
                }
                else{
                    st.push({s[i],1});
                }
                if(f==k)st.pop();

            }
            else st.push({s[i],1});

        }
        string ans;
        while(!st.empty()){
            int a=st.top().second;
            while(a--){
                ans.push_back(st.top().first);
            }
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};