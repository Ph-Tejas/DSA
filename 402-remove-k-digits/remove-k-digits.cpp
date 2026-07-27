class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        vector<vector<int>>v(n,vector<int>(10,10000000));
        
        for(int i=n-2;i>-1;i--){
            v[i]=v[i+1];
            v[i][num[i+1]-'0']=i+1;
        }
        string fin;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<10;j++){
                if(num[i]-'0'==j){
                    fin.push_back(j+'0');
                    break;
                }
                int loc=v[i][j];
                if(loc-i<=k){
                    k-=loc-i;
                    i=loc;
                    fin.push_back(j+'0');
                    break;
                }
            }
        }
        while(k--){
            fin.pop_back();
        }
        reverse(fin.begin(),fin.end());
        while(!fin.empty()&&fin.back()=='0'){
            fin.pop_back();
        }
        if(fin.empty())return "0";
        reverse(fin.begin(),fin.end());

        
        return fin;
    }
};