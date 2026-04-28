class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int>v;
        for(int i=1;i<=1000;i++){
            for(int j=i;j<=1000;j++){
                v[((i*i*i)+(j*j*j))]++;
                if((i*i*i)+(j*j*j)>n){
                    
                    break;
                }
            }
        }

        vector<int>ans;
        for(auto &val:v){
            if(val.first>n)break;
            if(val.second>1){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};