class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v(n,vector<int>(2));
        v[0][nums[0]]++;
        unordered_map<int,int>mp;
        mp[v[0][0]-v[0][1]]=0;
        for(int i=1;i<n;i++){
            v[i][0]=v[i-1][0];
            v[i][1]=v[i-1][1];
            v[i][nums[i]]++;
            mp[v[i][0]-v[i][1]]=i;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i==0){
                
                if(mp[0]!=0)maxi=max(mp[0]+1,maxi);
            }
            else{
                int curr=v[i-1][0]-v[i-1][1];
                if(mp[curr]!=i)maxi=max(maxi,mp[curr]-(i-1));
            }
        }

        return maxi;
        
        
        
    }






};