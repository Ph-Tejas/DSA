class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<int>v;
        int num=n;
        int it=0;
        while(num>0){
            if(num&1){

                v.push_back(it);
            }
            it++;
            num/=2;
        }
        reverse(v.begin(),v.end());

        vector<vector<int>>vp;
        for(int i=0;i<v.size();i+=2){
            if(i==v.size()-1){
                vp.push_back({v[i],-1});
                break;
            }
            vp.push_back({v[i],v[i+1]});

        }

        int ans=0;
        for(int i=0;i<vp.size();i++){
            int a=vp[i][0];
            int b=vp[i][1];
            if(b==-1){
                ans+=pow(2,a+1)-1;
                break;

            }
            ans+=pow(2,a);
            int diff=a-b-1;
            int itt=a;
            while(diff--){
        
                itt-=1;
                ans+=pow(2,itt);
            }
        }
        return ans; 




    }
};