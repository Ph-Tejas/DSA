class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& quesries) {
        int n=nums.size();
        int q=quesries.size();
        int maxi=*max_element(nums.begin(),nums.end());
        map<int,vector<int>>loc;
        for(int i=0;i<n;i++){
            loc[nums[i]].push_back(i);
            

        }
        vector<int>ans(n,INT_MAX);
        for(auto &val:loc){
            int sz=val.second.size();
            if(sz==1){
                ans[val.second[0]]=-1;
                continue;
            }
            int i=0;

            for(auto &curr:val.second){
                if(i==0){
                    ans[curr]=min(val.second[1]-curr,curr-(val.second[sz-1]-n));
                }
                else if(i==sz-1){
                    ans[curr]=min(curr-val.second[sz-2],(val.second[0]+n)-curr);
                }
                else{
                    ans[curr]=min(curr-val.second[i-1],val.second[i+1]-curr);
                }
                i++;
            }
        }
        vector<int>fin(q);
        for(int i=0;i<q;i++){
            
            int ind=quesries[i];
            fin[i]=ans[ind];
            
            

        }
        return fin;


    }
};