class Solution {
public:
    void swap(int i,int j,vector<int>&v){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int>sfz;
        for(int i=0;i<n;i++){
            int ct=0;
            for(int j=n-1;j>-1;j--){
                if(grid[i][j]==0){
                    ct++;
                }
                else break;
            }
            sfz.push_back(ct);
        }
        vector<int>act=sfz;
        sort(sfz.begin(),sfz.end(),[](int &A,int&B){
            return A>B;
        });
        int topp=n-1;
        for(int i=0;i<n;i++){
            if(sfz[i]<topp)return -1;
            topp--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            
            topp=n-1-i;
            if(act[i]>=topp)continue;
            int ind=-1;
            
            for(int j=i+1;j<n;j++){
                if(act[j]>=topp){
                    ind=j;
                    break;
                }
            }
            for(int j=ind;j>i;j--){
                swap(j-1,j,act);
                ans++;
            }
        }
        return ans;



    }
};