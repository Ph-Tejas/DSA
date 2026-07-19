class Solution {
public:
    bool finding(int i,vector<vector<int>>&v,set<int>&st){
        int flag=true;
        for(auto val:st){
            if(v[i][val]==0){
                flag=false;
                break;
            }
        }
        return flag;



    }
    string smallestSubsequence(string s) {
        int n=s.size();
        set<int>st;
        vector<vector<int>>v(n,vector<int>(26));
        v[n-1][s[n-1]-'a']++;
        
        st.insert(s[n-1]-'a');
        
        for(int i=n-2;i>-1;i--){
            v[i]=v[i+1];
            v[i][s[i]-'a']++;
            st.insert(s[i]-'a');
        }

        int it=it;
        string ans;
        int sz=st.size();
        while(!st.empty()){
            int a;
            for(auto val:st){
                int flag=false;
                for(int i=it;i<n;i++){
                    if(s[i]-'a'==val){
                        if(finding(i,v,st)){
                            a=val;
                            flag=true;
                            it=i;
                            break;
                        }

                    }
                }
                if(flag)break;
            }
            ans.push_back(a+'a');
            st.erase(a);


        }
        return ans;





    }
};