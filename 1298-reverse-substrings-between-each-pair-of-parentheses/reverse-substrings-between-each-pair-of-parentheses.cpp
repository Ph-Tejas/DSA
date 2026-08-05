class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string a;
                while(st.top()!='('){
                    a.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char &c:a){
                    st.push(c);
                }
                continue;
            }
            st.push(s[i]);

        }
        
        while(!st.empty()){
            if(st.top()!='(' &&st.top()!=')'){
                ans.push_back(st.top());
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};