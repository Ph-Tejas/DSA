class Solution {
public:
    vector<bool>vis;

    void build(string s,unordered_set<string>&toCheck,int &sz,vector<string>&available){
        
        
        if(count(vis.begin(),vis.end(),true)==sz)return;

        for(int j=0;j<sz;j++){
            if(vis[j])continue;
            s.push_back(available[j][0]);
            toCheck.insert(s);
            vis[j]=true;
            build(s,toCheck,sz,available);
            s.pop_back();
            vis[j]=false;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        
        int n=s.size();
        
        vector<int>freq(26);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        vector<string>available;
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
                while(freq[i]/k!=0){
                    string str;
                    str.push_back(i+'a');
                    available.push_back(str);
                    freq[i]-=k;
                }
            }

        }
        int sz=available.size();
        vis.resize(sz,false);
        unordered_set<string>toCheck;
        for(int i=0;i<sz;i++){
            toCheck.insert(available[i]);
            vis[i]=true;
            build(available[i],toCheck,sz,available);
            vis[i]=false;
        }
        sz=toCheck.size();
        vector<string>toChec;
        for(auto &stri:toCheck){
            toChec.push_back(stri);
        }
        sort(toChec.begin(),toChec.end(),[](string &a,string &b){
            if(a.size()==b.size()){
                return a>b;
            }
            return a.size()>b.size();
        });
        for(int i=0;i<sz;i++){
            int szz=toChec[i].size();
            int it=0;
            int ct=0;
            for(int j=0;j<n;j++){
                if(s[j]==toChec[i][it]){
                    it++;
                    if(it==szz){
                        ct++;
                        it=0;
                    }

                }
            }
            if(ct>=k)return toChec[i];

        }
        return "";

        

















    }
};