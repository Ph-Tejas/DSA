class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<int>st;
        int n=s.size();
        
        vector<unordered_set<int>>v(n);
        
        vector<stack<int>>vs(26);
        
        v[n-1].insert(s[n-1]-'a');

        for(int i=n-1;i>-1;i--){

            st.insert(s[i]-'a');
            
            vs[s[i]-'a'].push(i);
            
            if(i!=n-1){
                v[i]=v[i+1];
                v[i].insert(s[i]-'a');
            }
        }
        
        string ans;
       

        while(!st.empty()){
            for(auto &val:st)cout<<val<<" ";
            cout<<endl;
            
            int ct=-1;

            for(int i=0;i<26;i++){


                if(st.find(i)!=st.end()){

                    bool flag=true;

                    int ind=vs[i].top();
                    
                    for(auto &val:st){
                        if(v[ind].find(val)==v[ind].end()){
                            flag=false;
                        }
                    }


                    if(flag){

                        ans.push_back(i+'a');
                        st.erase(i);
                        ct=ind;
                        break;

                    }
                }

            }
            cout<<ct<<" "<<endl;
            for(int i=0;i<26;i++){
                while(!vs[i].empty() && vs[i].top()<ct)vs[i].pop();
            }
        }
        return ans;

    }
};