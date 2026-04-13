class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int,int> mp;  // changed

        for(int i = 0; i < n; i++){
            int curr = nums[i];
            mp[curr]++;
            if(mp[curr] > 2 && curr != 0) mp[curr] = 2;
        }

        vector<int> v;
        v.reserve(mp.size()); // added

        if(mp[0] > 2){
            ans.push_back({0,0,0});
            mp[0] = 1;
        }

        if(mp[0] == 2) mp[0] = 1;

        for(auto &val : mp){
            int x = val.first;  // added
            if(val.second == 2){
                if(mp.find(-2 * x) != mp.end()){
                    ans.push_back({x, x, -2 * x});
                }
                val.second = 1;
            }
            if(val.second == 1){
                v.push_back(x);
            }
        }

        vector<int> vis(200001, -1); // replaced 2e5+1
        n = v.size();

        for(int i = 0; i < n; i++){
            vis[v[i] + 100000] = i;
        }

        for(int i = 0; i < n; i++){
            int curr1 = v[i]; // moved out
            for(int j = i + 1; j < n; j++){
                int curr2 = v[j];
                int req = (-1 * (curr1 + curr2)) + 100000;

                if(req >= 0 && req <= 200000){
                    int idx = vis[req]; // added
                    if(idx > j){ // simplified condition
                        ans.push_back({curr1, curr2, req - 100000});
                    }
                }
            }
        }

        return ans;
    }
};