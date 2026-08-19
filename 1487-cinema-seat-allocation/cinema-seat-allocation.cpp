class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        int sz=nums.size();
        map<int,vector<int>>mp,mp1;

        for(int i=0;i<sz;i++){
            mp[nums[i][0]].push_back(nums[i][1]);
        }
        int it=1;

        for(auto &val:mp){

            mp1[it]=val.second;
            
            it++;
        }

        sz=mp1.size();
        vector<vector<bool>>v(sz,vector<bool>(3,true));
       
        for(auto &val:mp1){
            it=val.first;
            // cout<<it<<endl;
            for(auto &j:val.second){
                // cout<<j<<" ";
                if(j>=2 &&j<=3)v[it-1][0]=false;
                else if(j>=4 &&j<=5){
                    v[it-1][0]=false;
                    v[it-1][1]=false;
                }
                    
                else if(j>=6 &&j<=7){
                    v[it-1][1]=false;
                    v[it-1][2]=false;
                }
                else if(j>=8 &&j<=9){
                    v[it-1][2]=false;
                }

            }
            
            // cout<<endl;
        }
        int ct=0;
        for(int i=0;i<sz;i++){
            
            if(v[i][0] && v[i][2])ct+=2;
            else if(!v[i][0] && v[i][2])ct++;
            else if(v[i][0] && !v[i][2])ct++;
            else if(!v[i][0] && !v[i][2] && v[i][1])ct++;

            
        }

        ct+=2*(n-sz);
        return ct;



    }
};