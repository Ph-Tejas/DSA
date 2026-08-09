class Solution {
public:
    unordered_set<string>collect;
    int n;
    void build(int i,int ct,string &s,string &temp,int val){
        if(i==n){
            if(ct==0){
            cout<<temp<<" "<<val<<endl;
                if(val==0){
                    collect.insert(temp);
                }
            }
            return;


        }

        if(s[i]!='(' && s[i]!=')'){
            temp.push_back(s[i]);
            build(i+1,ct,s,temp,val);
            temp.pop_back();
        

        }
        else if(s[i]=='('){
            temp.push_back(s[i]);
            build(i+1,ct,s,temp,val+1);
            temp.pop_back();
            if(ct!=0)build(i+1,ct-1,s,temp,val);
        }
        else{
            if(val-1>=0){
            
                temp.push_back(s[i]);
                build(i+1,ct,s,temp,val-1);
                temp.pop_back();
                
                if(ct!=0){
                    build(i+1,ct-1,s,temp,val);
                }
            }
            else{
                if(ct!=0){
                    build(i+1,ct-1,s,temp,val);
                }
            }

        }


    }
    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        int ct=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(1);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    ct++;
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            ct+=1;
            st.pop();
        }
        string temp;
        build(0,ct,s,temp,0);

        vector<string>ans;
        for(auto &val:collect){
            ans.push_back(val);
        }

        return ans;






    }
};