class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=s.size();
        int sz=words.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'a'].push_back(i);
        }
        int ans=0;
        
        for(int i=0;i<sz;i++){
            int prev=-1;
            for(int j=0;j<words[i].size();j++){
                int curr=words[i][j]-'a';
                
                auto it=upper_bound(mp[curr].begin(),mp[curr].end(),prev);
                if(it==mp[curr].end())break;
                prev=*it;
                if(j==words[i].size()-1)ans++;

            }
        }
        return ans;
        


    }
};