class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s.insert(s.begin(),'1');
        s.push_back('1');
        int n=s.size();
        // cout<<n;
        vector<int>v;
        bool flag=false;
        int ct=0;
        bool start=false;
        int init=count(s.begin(),s.end(),'1')-2;
        // cout<<init;
        for(int i=0;i<n;i++){
            if(!flag){
                if(s[i]=='0'){
                    start=true;
                    ct++;
                }
                else{
                    if(start){
                        v.push_back(ct);
                        ct=0;
                        i--;
                        flag=true;
                    }
                }
            }
            else{
                if(s[i]=='1'){
                    ct++;
                }
                else{
                    flag=false;
                    v.push_back(ct);
                    ct=0;
                    i--;
                }
            }
        }
        
        
        n=v.size();
        int maxi=0;
        for(int i=0;i<n-1;i+=2){
            maxi=max(v[i]+v[i+2],maxi);
        }
        return init+maxi;
    }
};