class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();

        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[barcodes[i]]++;
        }

        vector<int>v(n);
        vector<vector<int>>vp;
        for(auto &val:mp){
            vp.push_back({val.second,val.first});
        }




        sort(vp.begin(),vp.end(),[](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });


        int it=0;
        vector<int>ans(n);
        for(int i=0;i<n;i+=2){
            ans[i]=vp[it][1];
            vp[it][0]--;
            if(vp[it][0]==0){
                it++;
            }
        }
        for(int i=1;i<n;i+=2){
            ans[i]=vp[it][1];
            vp[it][0]--;
            if(vp[it][0]==0){
                it++;
            }
        }
        return ans;
        



    }
};