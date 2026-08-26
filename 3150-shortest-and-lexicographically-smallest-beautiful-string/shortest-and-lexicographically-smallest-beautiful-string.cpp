class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]=='1')v.push_back(i);
        }


        if(v.size()<k)return "";
        vector<int>pr;
        int ans=INT_MAX;
        int ind=0;
        int i=0;
        int j=k-1;


        while(j<v.size()){
            if(ans>v[j]-v[i]+1){
                pr.clear();
                ans=v[j]-v[i]+1;
                pr.push_back(v[i]);
            }
            else if(ans==v[j]-v[i]+1){
                pr.push_back(v[i]);
            }
            i++;
            j++;
        }
        vector<string>a;
        for(int it=0;it<pr.size();it++){
            a.push_back(s.substr(pr[it],ans));
        }
        sort(a.begin(),a.end());
        return a[0];









    }
};