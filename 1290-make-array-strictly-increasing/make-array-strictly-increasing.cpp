struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:


    unordered_map<pair<int,int>, int, hash_pair> mp;
    int fun(int ind,int prev,vector<int>& arr1, vector<int>& arr2){
        if(ind==arr1.size())return 0;
        if(mp.find({ind,prev})!=mp.end()){
            return mp[{ind,prev}];
        }
        int changing;
        int notChanging;
        if(upper_bound(arr2.begin(),arr2.end(),prev)==arr2.end()){
            changing=1e9;
        }
        else {
            int val=(*upper_bound(arr2.begin(),arr2.end(),prev));
            changing=1+fun(ind+1,val,arr1,arr2);
        }
        if(arr1[ind]<=prev){
            notChanging=1e9;
            
        }
        else{
            notChanging=fun(ind+1,arr1[ind],arr1,arr2);
            
        }
        return mp[{ind,prev}]=min(changing,notChanging);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        sort(arr2.begin(),arr2.end());
        int ans=fun(0,-1,arr1,arr2);
        if(ans>=1e9)return -1;
        return ans;







    }
};