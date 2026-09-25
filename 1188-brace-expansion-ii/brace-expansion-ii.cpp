class Solution {
public:

    set<string> fun(string expression) {
        int n=expression.size();
        set<string>fin;
        int B=0;
        bool flag=false;
        if(expression[0]!='{')flag=true;

        for(int i=0;i<n;i++){
            if(expression[i]=='{')B++;
            else if(expression[i]=='}'){
                B--;
                if(B==0 && i!=n-1)flag=true;
            }
        }        
        if(flag){
            vector<set<string>>v;
            
            for(int i=0;i<n;i++){
                if(expression[i]=='{'){
                    int c=1;

                    string s="{";
                    i++;
                    while(i<n &&c>0){
                        if(expression[i]=='{'){
                            c++;
                        }
                        else if(expression[i]=='}')c--;
                        s.push_back(expression[i]);
                        i++;
                        

                    }
                    set<string>stt=fun(s);
                    v.push_back(stt);
                    i--;

                    
                }
                else{
                    string s;
                    while(i!=n && expression[i]!='{'){
                        
                        s.push_back(expression[i]);
                        i++;
                        

                    }
                    set<string>stt;
                    stt.insert(s);
                    v.push_back(stt);
                    i--;
                }

            }

            set<string>ans;
            set<string>temp=v[0];
            for(int i=1;i<v.size();i++){
                for(auto &val:v[i]){
                    for(auto &val1:temp){
                        ans.insert(val1+val);
                    }
                }
                temp=ans;
                ans.clear();
            }
            return temp;
            



        }
        else{
            set<string>st;


            int b=0;
            string s;
            expression[n-1]=',';
            for(int i=1;i<n;i++){
                if(expression[i]==','){
                    if(b==0){
                        st.insert(s);
                        s.clear();

                        continue;

                    }
                }
                else if(expression[i]=='{'){
                    b++;
                    
                }
                else if(expression[i]=='}'){
                    b--;
                }

                s.push_back(expression[i]);



            }
            
            for(auto &val:st){
                // cout<<val<<" ";
                set<string> st1=fun(val);
                for(auto &val1:st1){
                    fin.insert(val1);
                }


            }
        }
        return fin;


    }
    
    vector<string> braceExpansionII(string expression) {
        
        set<string>st=fun(expression);
        vector<string>ans;
        for(auto &str:st){
            ans.push_back(str);
        }
        return ans;


    }
};