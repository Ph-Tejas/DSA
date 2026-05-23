class Solution {
public:
    void fun(int I,int J,vector<vector<int>>& matrix){
        int sz=(J-I)*4;
        int ln=J-I;
        map<int,pair<pair<int,int>,int>>mp;
        int ct=0;
        for(int i=I;i<=J;i++){
            // loc.push_back(matrix[I][i]);
            mp[ct]={{I,i},matrix[I][i]};
            ct++;

        }
        for(int i=I+1;i<=J;i++){
            // loc.push_back(matrix[i][J]);
            mp[ct]={{i,J},matrix[i][J]};
            ct++;
        }
        for(int i=J-1;i>=I;i--){
            // loc.push_back(matrix[J][i]);
            mp[ct]={{J,i},matrix[J][i]};
            ct++;
        }
        for(int i=J-1;i>I;i--){
            // loc.push_back(matrix[i][I]);
            mp[ct]={{i,I},matrix[i][I]};
            ct++;
        }
        for(auto &val:mp){
            int x=mp[(val.first+ln)%sz].first.first;
            int y=mp[(val.first+ln)%sz].first.second;
            matrix[x][y]=val.second.second;
        }


        
        

    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            fun(i,n-1-i,matrix);
        }
    }
};