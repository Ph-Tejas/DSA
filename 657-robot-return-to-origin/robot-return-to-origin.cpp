class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0;
        int b=0;
        for(auto val:moves){
            
            if(val=='U')a++;
            if(val=='D')a--;
            if(val=='L')b++;
            if(val=='R')b--;
            
        }
        if(a==0&&b==0)return true;
        return false;
    }
};