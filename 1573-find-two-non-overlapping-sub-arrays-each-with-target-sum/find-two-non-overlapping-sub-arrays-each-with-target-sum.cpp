class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>pf(n+1);
        for(int i=1;i<=n;i++){
            pf[i]=pf[i-1]+arr[i-1];
        }
        vector<int>tgt;
        for(int i=1;i<=n;i++){
           
            auto it=lower_bound(pf.begin(),pf.end(),pf[i-1]+target);

            if(it!=pf.end() && (*it)==pf[i-1]+target){
                tgt.push_back((it-pf.begin())-1);
            }
            else{
                tgt.push_back(-1);
            }
        }   
        for(int i=0;i<n;i++){
            if(tgt[i]!=-1){
                tgt[i]=(tgt[i]-i+1);
            }
        }
        
        vector<int>tgt_s=tgt;
        int ans=INT_MAX;
        for(int i=n-2;i>-1;i--){
            if(tgt_s[i]==-1){
                tgt_s[i]=tgt_s[i+1];
            }
            else{
                if(tgt_s[i+1]!=-1)tgt_s[i]=min(tgt_s[i],tgt_s[i+1]);
            }
        }

        for(int i=0;i<n;i++){
            if(tgt[i]!=-1){
                if(i+tgt[i]!=n){
                    if(tgt_s[i+tgt[i]]!=-1){
                        ans=min(ans,tgt[i]+tgt_s[i+tgt[i]]);
                    }
                }
            }
        }
        return ((ans==INT_MAX)?-1:ans);

        
    }
};