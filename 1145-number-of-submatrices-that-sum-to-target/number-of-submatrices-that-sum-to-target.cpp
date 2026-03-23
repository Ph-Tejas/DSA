class Solution {
public:
    Solution()
    {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base :: sync_with_stdio(false);
    }
    int solve(vector<int>& col,int target){
        int n=col.size();
        unordered_map<int,int> mp;//sum,freq
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum +=col[i];
            int need=sum-target;
            if(mp.find(need)!=mp.end()) ans+=mp[need];
            mp[sum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){ //time-O(n^3)
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int c1=0;c1<n;c1++){
            vector<int> col(m,0);
            for(int c2=c1;c2<n;c2++){
                for(int r=0;r<m;r++){
                    col[r]+=matrix[r][c2];
                }
                ans+=solve(col,target);
            }
        }
        return ans;
    }
};