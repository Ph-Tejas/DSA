class Solution {
public:
    int trailingZeroes(int n) {
        vector<pair<int,int>>v;
        
        int num,ct1,ct2;
        int ans=0;
        ct1=0;
        ct2=0;
        for(int i=1;i<=n;i++){
            num=i;
            while(num%2==0){
                num/=2;
                ct1++;
            }
            while(num%5==0){
                num/=5;
                ct2++;
            }

        }
        return min(ct1,ct2);


    }
};