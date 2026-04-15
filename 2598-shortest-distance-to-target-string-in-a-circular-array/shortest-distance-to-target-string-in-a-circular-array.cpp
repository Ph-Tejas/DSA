class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        map<string,vector<int>>st;
        int n=words.size();
        for(int i=0;i<n;i++){
            st[words[i]].push_back(i);
        }
        if(st.find(target)!=st.end()){
            int mini=INT_MAX;
            for(int val:st[target]){
                if(startIndex>=val){
                    mini=min(mini,abs(startIndex-val-n));

                }
                else{
                    mini=min(mini,abs(startIndex-val+n));

                }
                mini=min(mini,abs(val-startIndex));
                
            }
            return mini;
        }
        return -1;

    }
};