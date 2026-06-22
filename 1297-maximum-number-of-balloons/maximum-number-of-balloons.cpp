class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[text[i]-'a']++;
        }
        int mini=INT_MAX;
        mini=min(mini,mp['b'-'a']);
        mini=min(mini,mp['a'-'a']);
        mini=min(mini,mp['l'-'a']/2);
        mini=min(mini,mp['o'-'a']/2);
        mini=min(mini,mp['n'-'a']);
        // mini=min(mini,mp['b'-'a']);
        return mini;
        
        
    }
};