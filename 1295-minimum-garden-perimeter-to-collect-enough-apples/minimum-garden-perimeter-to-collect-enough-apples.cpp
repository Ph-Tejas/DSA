class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long ct=12;
        long long it=12;
        if(neededApples<=12)return 8;
        for(int i=2;;i++){
            it+=((i-1)*8)+4;
            it+=(2*i-1)*8;
            if(i==2)cout<<it;
            ct+=it;
            if(ct>=neededApples)return 8*i;
        }   
    }
};