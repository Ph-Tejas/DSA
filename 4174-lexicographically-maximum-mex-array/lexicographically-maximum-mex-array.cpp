class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>present(maxi+2);

        vector<int>mex_suff(n);
        int it=0;
        for(int i=n-1;i>-1;i--){
        
            present[nums[i]]++;
            while(present[it]!=0){
                it++;
            }
            mex_suff[i]=it;
            
        }
        for(int i=0;i<maxi+2;i++){
            present[i]=0;
        }
        it=0;
        vector<int>ans;
        int tgt=mex_suff[0];
        stack<int>should_delete;
        for(int i=0;i<n;i++){
            present[nums[i]]++;
            should_delete.push(nums[i]);
            while(present[it]!=0){
                it++;
            }
            if(it==tgt){
                ans.push_back(it);
                while(!should_delete.empty()){
                    present[should_delete.top()]--;
                    should_delete.pop();
                }
                it=0;
                if(i+1<n)tgt=mex_suff[i+1];

                
            }
            


            
        }
        return ans;











    }
};