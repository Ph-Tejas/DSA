class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();

        string prep;
        for(int i=0;i<n;i++){
            prep.push_back(s[i]);
            if(prep.size()>=m){
                if(prep.substr(prep.size()-m)==part){
                    int k=m;
                    while(k--)prep.pop_back();
                }
            }
        }
        return prep;
    }
};