class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.size();

        string s_=s;
        sort(s_.begin(),s_.end());
        if(k>1)return s_;
        string temp=s;
        string ref=s;
        
        for(int i=0;i<n-1;i++){
            ref=s.substr(i+1)+s.substr(0,i+1);
            if(temp>ref){
                temp=ref;
            }

        }
        return temp;
    }
};