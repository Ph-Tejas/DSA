class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string temp;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(temp.size());
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else continue;
            }
            temp.push_back(s[i]);
            
        }
        while(!st.empty()){
            
            temp[st.top()]='.';
            st.pop();
        }
        
        string ans;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!='.')ans.push_back(temp[i]);
        }
        return ans;

    }
};