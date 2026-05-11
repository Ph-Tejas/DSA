class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        map<string,int>mp;
        int n=chunks.size();
        int sz=queries.size();
        string temp;
        int ct=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<chunks[i].size();j++){
                if(chunks[i][j]!='-'&&chunks[i][j]!=' '){
                    if(ct>1){
                        temp.push_back(' ');
                    }
                    else if(ct==1){
                        temp.push_back('-');
                    }
                    ct=0;
                    temp.push_back(chunks[i][j]);

                }
                else if(chunks[i][j]==' '){

                    ct=0;
                    temp.push_back(' ');

                }
                else{
                    if(temp.empty()||temp.back()==' '){
                        continue;
                    }
                    ct++;
                }
                
            }
        }
        string s;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==' '){
                mp[s]++;
                s="";
                continue;
            }
            s.push_back(temp[i]);

        }
        if(!s.empty()){
            mp[s]++;
        }
        cout<<temp;
        vector<int>ans;
        for(int i=0;i<sz;i++){
            ans.push_back(mp[queries[i]]);
        }
        return ans;
    }
};