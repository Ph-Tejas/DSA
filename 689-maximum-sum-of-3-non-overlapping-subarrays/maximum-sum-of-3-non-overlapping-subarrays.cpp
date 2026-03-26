class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v;
        int v_f=accumulate(nums.begin(),nums.begin()+k,0);

        v.push_back(v_f);
        for(int i=k;i<n;i++){
            v_f-=nums[i-k];
            v_f+=nums[i];
            v.push_back(v_f);
        }
        int sz=v.size();
        vector<int>v_front(sz,v[0]);
        vector<int>v_find(sz,0);
        int maxi=v[0];
        int ind=0;
        for(int i=1;i<sz;i++){

            if(maxi<v[i]){
                maxi=v[i];
                ind=i;
            }
        
            v_find[i]=ind;
            v_front[i]=maxi;
        }
        

        vector<int>v_back(sz,v[sz-1]);
        vector<int>v_bind(sz,sz-1);
        maxi=v[sz-1];
        ind=sz-1;
        for(int i=sz-2;i>-1;i--){
            if(maxi<=v[i]){
                maxi=v[i];
                ind=i;
            }
            v_bind[i]=ind;

            v_back[i]=maxi;
        }
        vector<int>ans={0,0,0};
        maxi=-1;
        for(int i=k;i<sz-k;i++){
            if(maxi<v_front[i-k]+v_back[i+k]+v[i]){
                maxi=v_front[i-k]+v_back[i+k]+v[i];
                ans={v_find[i-k],i,v_bind[i+k]};
            }
        }
        return ans;



    }
};