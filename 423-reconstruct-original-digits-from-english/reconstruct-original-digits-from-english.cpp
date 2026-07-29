class Solution {
public:
    string originalDigits(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        string ans;
        while(mp['z']>0 && mp['e']>0 && mp['r']>0 && mp['o']>0){
            ans.push_back('0');
            mp['z']--;
            mp['e']--;
            mp['r']--;
            mp['o']--;
        }
        while(mp['i']>0 && mp['e']>0 && mp['g']>0 && mp['h']>0&& mp['t']>0){
            ans.push_back('8');
            mp['e']--;
            mp['i']--;
            mp['g']--;
            mp['h']--;
            mp['t']--;
        }
        while(mp['f']>0 && mp['u']>0 && mp['r']>0 && mp['o']>0){
            ans.push_back('4');
            mp['f']--;
            mp['u']--;
            mp['r']--;
            mp['o']--;
        }
        while(mp['t']>0 && mp['w']>0 && mp['o']>0){
            ans.push_back('2');
            mp['t']--;
            mp['w']--;
            // mp['r']--;
            mp['o']--;
        }
        while(mp['s']>0 && mp['i']>0 && mp['x']>0 ){
            ans.push_back('6');
            mp['s']--;
            mp['i']--;
            mp['x']--;
            // mp['o']--;
        }





        while(mp['s']>0 && mp['e']>1 && mp['v']>0 && mp['n']>0){
            ans.push_back('7');
            mp['s']--;
            mp['e']-=2;
            mp['v']--;
            mp['n']--;
        }



        while(mp['t']>0 && mp['e']>1 && mp['r']>0 && mp['h']>0){
            ans.push_back('3');
            mp['t']--;
            mp['e']-=2;
            mp['r']--;
            mp['h']--;
        }


        while(mp['n']>0 && mp['e']>0 && mp['o']>0){
            ans.push_back('1');
            mp['n']--;
            mp['e']--;
            mp['o']--;
        }



        while(mp['n']>1 && mp['e']>0 && mp['i']>0 ){
            ans.push_back('9');
            mp['n']-=2;
            mp['e']--;
            mp['i']--;
        }
        while(mp['f']>0 && mp['e']>0 && mp['i']>0 && mp['v']>0){
            ans.push_back('5');
            mp['f']--;
            mp['e']--;
            mp['v']--;
            mp['i']--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};