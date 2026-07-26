class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            vector<int>v(26);
            int num=i;
            int it=0;
            int ct=0;
            bool flag=true;
            while(num>0){
                if(num&1){
                    ct+=arr[it].size();
                    for(int j=0;j<arr[it].size();j++){
                        if(v[arr[it][j]-'a']==1)flag=false;
                        else v[arr[it][j]-'a']=1;
                    }
                }
                it++;
                num/=2;
            }
            if(flag)ans=max(ans,ct);
        }
        return ans;
    }
};