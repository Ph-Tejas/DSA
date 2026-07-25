class Solution {
public:
    vector<int>v;
    bool makesquare(vector<int>& nums) {
        int n=nums.size();
        int tgt=accumulate(nums.begin(),nums.end(),0);
        if(tgt%4)return false;
        tgt/=4;
        for(int i=1;i<(1<<n);i++){
            int ct=0;
            int it=0;
            int num=i;

            while(num>0){
                if(num&1){
                    ct+=nums[it];
                }
                it++;
                num/=2;
            }
            if(ct==tgt){
                v.push_back(i);
            }
        }
        int sz=v.size();

        if(sz<4)return false;
        
        for(int i=0;i<sz;i++){
            int num=v[i];
            

            for(int j=i+1;j<sz;j++){
                int num1=-1;
                if((num^v[j])!=(num+v[j]))continue;
                else num1=num+v[j];    
                for(int k=j+1;k<sz;k++){
                    int num2=-1;
                    if((num1^v[k])!=(num1+v[k]))continue;
                    else num2=num1+v[k]; 
                    for(int l=k+1;l<sz;l++){
                        int num3=-1;
                        if((num2^v[l])!=(num2+v[l]))continue;
                        else num3=num+v[l]; 
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
};