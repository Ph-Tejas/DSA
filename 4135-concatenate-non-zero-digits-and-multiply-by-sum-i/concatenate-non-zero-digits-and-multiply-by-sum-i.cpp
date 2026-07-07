class Solution {
public:
    long long sumAndMultiply(int n) {
        string num=to_string(n);
        int ans=0;
        string x;
        for(int i=0;i<num.size();i++){
            
            ans+=(num[i]-'0');
            if(num[i]!='0'){
                x.push_back(num[i]);
            }
        }
        if(x.empty())return ans;
        return (long long)stoi(x)*ans;
    }
};