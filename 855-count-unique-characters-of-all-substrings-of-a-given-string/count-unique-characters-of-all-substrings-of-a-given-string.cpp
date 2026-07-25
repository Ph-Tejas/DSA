class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>>v(26,{-1});
        vector<vector<int>>vv(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            v[s[i]-'A'].push_back(i);
        }
        for(int i=0;i<26;i++){
            v[i].push_back(n);
            for(int j=1;j<v[i].size();j++){
                vv[i].push_back(v[i][j]-v[i][j-1]-1);
            }
        }
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<vv[i].size();j++){
        //         cout<<vv[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;

        for(int i=0;i<26;i++){
            if(vv[i].size()==1)continue;
            for(int j=0;j<vv[i].size()-1;j++){
                ans+=(vv[i][j]*vv[i][j+1])+1+vv[i][j]+vv[i][j+1];
            }
        }

        return ans;



    }
};