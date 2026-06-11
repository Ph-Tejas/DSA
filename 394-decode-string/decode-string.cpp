class Solution {
public:
    string decodeString(string s) {
        string newString;
        string garage;
        while(true){
            bool flag=false;
            int mul=1;
            int n=s.size();
            stack<int>st;
            int it=0;
            while(it<n){
                if(!flag){
                    if(s[it]-'0'<=9&&s[it]-'0'>=0){
                        string num;
                        while(s[it]<='9'&&s[it]>='0'){

                            num.push_back(s[it]);
                            it++;
                        }
                        

                        mul=stoi(num);
                        
                        continue;

                    }
                    if(s[it]=='['){
                        flag=true;
                        st.push(1);
                        garage.push_back('[');
                        it++;
                        continue;
                    }
                    newString.push_back(s[it]);
                    it++;
                }
                else{
                    while(!st.empty()){
                        garage.push_back(s[it]);
                        if(s[it]=='['){
                            st.push(1);
                        }
                        else if(s[it]==']'){
                            st.pop();
                        }
                        it++;
                    }

                    int sz=garage.size();
                    if(sz-2!=0){
                        while(mul--)newString+=garage.substr(1,sz-2);
                    }
                    garage.clear();
                    flag=false;
                    
                }

            }
        
            s.clear();
            s=move(newString);
            if(count(s.begin(),s.end(),'[')==0)break;

            

        }
        return s;
    }
};