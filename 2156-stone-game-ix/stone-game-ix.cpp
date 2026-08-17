class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int>v(3);
        for(int i=0;i<n;i++){
            v[stones[i]%3]++;

        }
        if(v[0]==n)return false;
        vector<int>store=v;
        bool f1=false;
        if(v[1]!=0){
            int ct=1;
            v[1]--;

            while(true){
                if(v[1]!=0){
                    v[1]--;
                    ct++;
                }
                else break;
                if(v[2]!=0){
                    v[2]--;
                    ct++;
                }
                else break;
                

            }

            if(v[1]!=0 || v[2]!=0){
                if(ct&1){
                    if((v[0]&1)==0)f1=true;
                }
                else {
                    if((v[0]&1))f1=true;
                }
            }
            
        }
        bool f2=false;
        if(store[2]!=0){
            int ct=1;
            store[2]--;

            while(true){
                if(store[2]!=0){
                    store[2]--;
                    ct++;
                }
                else break;
                if(store[1]!=0){
                    store[1]--;
                    ct++;
                }
                else break;
                

            }

            if(store[1]!=0 || store[2]!=0){
                if(ct&1){
                    if((store[0]&1)==0)f2=true;
                }

                else {
                    if((store[0]&1))f2=true;
                }
                
            }
            
        }

        return f1||f2;




    }
};