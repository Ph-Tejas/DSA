class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        long long n=arr1.size();
        long long m=arr2.size();
        int ans=0;
        for(int i=0;i<31;i++){
            
            long long z1=0,o1=0,z2=0,o2=0;
            
            for(int j=0;j<n;j++){
                if(((arr1[j]>>i)&1)){
                    o1++;
                }
                else z1++;
            }
            for(int j=0;j<m;j++){
                if(((arr2[j]>>i)&1)){
                    o2++;
                }
                else z2++;
            }
            long long nz=z1*m+o1*z2;
            long long no=n*m-nz;
            if(no&1){
                if(no>1)nz+=1;
                no=1;
            }
            else {
                if(no>0)nz+=1;
                no=0;
            }
            nz=(min(1LL,nz));
            if((no==1)){
                ans+=(1<<i);
            }
            

            



        }
        return ans;
        
        
    }
};