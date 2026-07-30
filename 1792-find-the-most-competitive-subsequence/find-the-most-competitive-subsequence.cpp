class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        set<pair<int,int>>st;
        int j=n-k;
        int prev=-1;
        for(int i=0;i<=j;i++){
            st.insert({nums[i],i});
        }
        vector<int>ans;
        while(j<n && k--){
            while((*st.begin()).second<=prev)st.erase(st.begin());
            auto it=st.begin();
            ans.push_back((*it).first);
            prev=((*it).second);
            st.erase(it);
            j++;
            if(j!=n)st.insert({nums[j],j});

        }
        return ans;

    }
};