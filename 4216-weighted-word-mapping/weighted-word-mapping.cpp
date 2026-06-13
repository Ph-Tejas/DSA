class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char,int>wt;
        unordered_map<int,char>ch;
        for(int i=0;i<26;i++){
            ch[25-i]='a'+i;
        }
        for(int i=0;i<26;i++){
            wt['a'+i]=weights[i];
        }
        string ans;
        for(int i=0;i<words.size();i++){
            int sm=0;
            for(auto chh:words[i]){
                sm+=(wt[chh]);
            }
            sm%=26;
            ans.push_back(ch[sm]);
        }
        return ans;
        
        
    }
};