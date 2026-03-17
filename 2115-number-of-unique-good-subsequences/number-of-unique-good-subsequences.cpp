class Solution {
public:
int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {

        string nBinary;
        bool flag=false;
        int ct=0;
        for(int i=0;i<binary.size();i++){
            if(binary[i]=='0')ct++;
            if(!flag){
                if(binary[i]=='1')flag=true;
                else continue;
            }
            nBinary.push_back(binary[i]);
        }
        int n=nBinary.size();
        if(n==0)return 1;
        vector<int>dp(n);
        int o=-1,z=-1;
        if(nBinary[n-1]=='0'){
            z=n-1;

        }
        else{
            o=n-1;
        }
        dp[n-1]=1;
        for(int i=n-2;i>-1;i--){
            long long sum=1;
            if(!(z==-1)){
                sum+=dp[z];
            }
            if(!(o==-1)){
                sum+=dp[o];
            }
            if(nBinary[i]=='0'){
                z=i;
            }
            else o=i;
            dp[i]=sum%mod;
        }
        return ((ct!=0)?(dp[0]+1):dp[0]);



    }
};