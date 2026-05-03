class Solution {
public:
    string sortVowels(string s) {
        vector<int>fc(26,-1);
        string vow="aeiou";
        vector<int>freq(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')freq[s[i]-'a']++;
            if(fc[s[i]-'a']!=-1)continue;
            fc[s[i]-'a']=i;

        }
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')s[i]=' ';
            
        }
        vector<vector<int>>v;
        for(int i=0;i<5;i++){
            v.push_back({freq[vow[i]-'a'],fc[vow[i]-'a'],vow[i]-'a'});    
        }
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        string d;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i][0];j++){

                d.push_back(v[i][2]+'a');
            }
        }
        int it=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                s[i]=d[it];
                it++;
            }
        }
        return s;


        
    }
};