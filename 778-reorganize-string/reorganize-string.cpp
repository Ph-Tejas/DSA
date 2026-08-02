class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        if(n==1)return s;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }

        if(mp.size()==1)return "";
        vector<pair<int,int>>v;
        for(auto &val:mp){
            v.push_back({val.second,val.first});
            cout<<val.second<<" "<<val.first<<endl;
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int sz=v.size();
        string ans;
        
        while(v[0].first!=v[1].first && v.back().second!=v[1].second){
            ans.push_back(v[0].second+'a');
            ans.push_back(v.back().second+'a');
            v[0].first--;
            v.back().first--;
            if(v.back().first==0)v.pop_back();
            
        }
        

        while(!v.empty()){

            for(int i=0;i<v.size();i++){
                ans.push_back(v[i].second+'a');
                v[i].first--;

                
                
            }
            while(!v.empty() && v.back().first==0)v.pop_back();
        }
        int k=ans.size();
        if(ans[k-1]==ans[k-2])return "";
        return ans;

    }
};