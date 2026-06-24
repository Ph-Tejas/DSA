class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>st;
        
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                string s;
                if(!st.empty()&&st.top()=="/"){
                    continue;
                }
                s.push_back('/');
                st.push(s);
            }
            else if(path[i]=='.'){
                int ct=0;
                while(i<n&&path[i]=='.'){
                    ct++;
                    i++;
                }
                if(i!=n&&path[i]!='/'){
                    string s;
                    for(int k=0;k<ct;k++){
                        s.push_back('.');
                    }
                    while(i<n&&path[i]!='/'){
                        s.push_back(path[i]);
                        i++;
                    }
                    st.push(s);

                }
                else if(ct==1){
                    continue;
                }
                else if(ct==2){
                    while(!st.empty()&&st.top()=="/"){
                        st.pop();
                    }
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else{
                    string s;
                    for(int k=0;k<ct;k++){
                        s.push_back('.');
                    }
                    st.push(s);
                }
                i--;
            }
            else{
                string s;
                while(i<n&&path[i]!='/'){
                    s.push_back(path[i]);
                    i++;
                }
                st.push(s);
                i--;
                
            }
        }
        stack<string>fin;
        string ans;
        while(!st.empty()){
            fin.push(st.top());
            st.pop();
        }
        
        while(!fin.empty()){
            ans+=fin.top();
            fin.pop();
        }
        if(ans.empty())return "/";
        while(!ans.empty()&&ans.back()=='/')ans.pop_back();
        if(ans.empty())return "/";
        return ans;
    }
};