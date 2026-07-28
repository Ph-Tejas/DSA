class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0;i<n/2;i++){
            mp[s[i]]++;
        }
        string ans;

        for(auto &val:mp){
            while(val.second--)ans.push_back(val.first);
        }
        int it=ans.size()-1;
        if(n&1){
            ans.push_back(s[n/2]);
        }
        while(it>-1){
            ans.push_back(ans[it]);
            it--;
        }
        return ans;

        
    }
};