class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();

        map<int,int>mp;
        int i=0;
        int ans=1;
        for(int j=0;j<n;j++){
            while(i>j)j++;
            if(j==n)break;
            int curr=nums[j];
            
            mp[curr]=j;
            auto it1=mp.begin();
            auto it2=mp.end();
            it2--;

            while(!mp.empty() && ((*it2).first)-((*it1).first)>limit){
                while(!mp.empty() && (*it1).second<i){
                
                    mp.erase((*it1).first);
                    it1=mp.begin();
                    it2=mp.end();
                    if(!mp.empty())it2--;
                }
                while(!mp.empty() && (*(it2)).second<i){

                    mp.erase((*(it2)).first);
                    it1=mp.begin();
                    it2=mp.end();
                    if(!mp.empty())it2--;
                }
                if(mp.empty())continue;

                if(((*it1).second)>(*it2).second){
                    i=(*it2).second+1;
                    mp.erase((*it2).first);
                }
                else if(((*it1).second)<(*it2).second){
                    i=(*it1).second+1;
                    mp.erase((*it1).first);
                }


                it1=mp.begin();
                it2=mp.end();
                if(!mp.empty())it2--;

                while(!mp.empty() && (*it1).second<i){
                
                    mp.erase((*it1).first);
                    it1=mp.begin();
                    it2=mp.end();
                    if(!mp.empty())it2--;
                }
                while(!mp.empty() && (*(it2)).second<i){

                    mp.erase((*(it2)).first);
                    it1=mp.begin();
                    it2=mp.end();
                    if(!mp.empty())it2--;
                }
                if(mp.empty())continue;
                
                
            }
            ans=max(j-i+1,ans);
            

        
        }
        return ans;



    }
};