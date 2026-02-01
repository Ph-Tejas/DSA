class Solution {
public:
    long long mod=1e9+7;
    vector<int>pf,sf;
    vector<int>pf_max;
    vector<pair<int,int>>vp;
    int kadane(vector<int>&arr){
        
        int sum=0;
        int ans=0;
        for(int j=0;j<arr.size();j++){
            sum+=arr[j];
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);
        }
        return ans;



    }
    void for_vp(vector<int>&arr,int ans_max){
        int i=0;
        int sum=0;
        for(int j=0;j<arr.size();j++){
            sum+=arr[j];
            if(sum<0){
                i=j+1;
                sum=0;
            }
            if(sum==ans_max){
                vp.push_back({i,j});
            }
        }
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        pf.resize(n);
        sf.resize(n);
        pf_max.resize(n);
        pf[0]=(arr[0]);
        long long ans=0;
        sf[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+arr[i];
        }
        int maxi=INT_MIN;
        for(int i=1;i<n;i++){
            maxi=max(maxi,pf[i-1]);
            pf_max[i]=maxi;
        }
        for(int i=n-2;i>-1;i--){
            sf[i]=sf[i+1]+arr[i];
        }
        int max_sum=kadane(arr);
        if(k==1)return max_sum;
        for_vp(arr,max_sum);
        if(max_sum==0)return 0;

        for(int i=0;i<vp.size();i++){
            int I=vp[i].first;
            int J=vp[i].second;
            int st;
            if(I==0)st=0;
            else{
                st=pf[I-1];
            }
            int en;
            if(J==n-1)en=0;
            else{
                en=pf[n-1]-pf[J];
            }
            ans=ans+max_sum;
            int tot=st+en;

            ans=(long long)k*pf[n-1]-st-en;
            if(ans<pf[J]-st)ans=pf[J]-st;
            if(ans<pf[n-1]-st+pf_max[I])ans=pf[n-1]-st+pf_max[I];



        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(ans<sf[0])ans=sf[0];

            }
            else {
                if(ans<sf[i]+pf_max[i])ans=sf[i]+pf_max[i];
            }
        }
        
        return ans%mod;




        

    }
};