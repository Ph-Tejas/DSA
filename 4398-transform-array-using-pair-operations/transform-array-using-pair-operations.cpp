class Solution {
public:
    bool canTransform(vector<int>& s, vector<int>& t) {
        vector<long long>source,target;

        int n=s.size();
        for(int i=0;i<n;i++){
            source.push_back(s[i]);
            target.push_back(t[i]);
        }
        if(accumulate(source.begin(),source.end(),0*1LL)==accumulate(target.begin(),target.end(),0*1LL))return true;
        return false;
    }
};