class Solution {
public:
    int gcd(int a,int b){
        if(b>a){
            int temp=a;
            a=b;
            b=temp;
        }
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>v(maxi+1);
        int ct=0;
        vector<bool>present(maxi+1);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            present[curr]=true;
        }


        for(int i=1;i<=maxi;i++){
            int letsGCD=-1;
            for(int j=i;j<=maxi;j+=i){
                if(letsGCD==-1&&present[j]){
                    letsGCD=j;
                }
                else if(present[j]){
                    letsGCD=gcd(letsGCD,j);
                    if(letsGCD==i)break;
                }
            }
            if(letsGCD==i){
                ct++;
            }
        }
        return ct;
        


    }
};