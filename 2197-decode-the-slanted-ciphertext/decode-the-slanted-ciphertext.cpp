class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n=encodedText.size();
        int it=0;
        int m=n/rows;
        if(n==0)return "";
        vector<vector<char>>v(rows,vector<char>(m));
        string ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<m;j++){
                v[i][j]=encodedText[it];
                it++;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<rows;j++){

                if(i+j<m)ans.push_back(v[j][i+j]);
            }
        }
        while(ans.back()==' ')ans.pop_back();
        return ans;

    }
};