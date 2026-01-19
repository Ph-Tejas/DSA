class Solution {
public:
    vector<vector<int>>tree1;
    int mod=1e9+7;
    long long traverse(int node,vector<int>& nums,vector<long long>&dp){
        if(dp[node]!=-1)return dp[node];
        long long maxi=0;
        
        for(int i=0;i<tree1[node].size();i++){
            long long l=traverse(tree1[node][i],nums,dp);
            if(maxi<l){

                maxi=l;
            }
        }
        maxi+=nums[node];
        return dp[node]=maxi;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>comb1;
        unordered_map<int,int>mp1,mp2;
        tree1.resize(n+m);
        for(int i=0;i<n;i++){
            mp1[nums1[i]]=i;
            comb1.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            comb1.push_back(nums2[i]);
            mp2[nums2[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(i!=n-1)tree1[i].push_back(i+1);

            if(mp2.find(nums1[i])!=mp2.end()){
                int a=mp2[nums1[i]];
                if(a!=m-1){
                    tree1[i].push_back(a+1+n);
                }
                if(i!=n-1){
                    tree1[a+n].push_back(i+1);
                }
                
                
            }
        
        
        }
        for(int i=0;i<m-1;i++){
            tree1[n+i].push_back(n+i+1);
        }
        vector<long long>dp(n+m,-1);

    
        
        long long ans1=traverse(0,comb1,dp);
        long long ans2=traverse(n,comb1,dp);
        if(ans1>ans2)return ans1%mod;
        return ans2%mod;
        


    }
};