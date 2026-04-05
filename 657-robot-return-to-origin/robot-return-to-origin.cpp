class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0;
        int b=0;
        for(int i=0;i<moves.size();i++){
            int curr=moves[i];
            if(curr=='U')a++;
            if(curr=='D')a--;
            if(curr=='L')b++;
            if(curr=='R')b--;
            
        }
        if(a==0&&b==0)return true;
        return false;
    }
};