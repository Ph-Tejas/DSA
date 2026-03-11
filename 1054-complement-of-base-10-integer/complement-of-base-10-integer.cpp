class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int sum=0;
        int ct=0;
        while(n>0){
            if(!(n&1))sum+=(1<<ct);
            ct++;
            n=n/2;
        }
        return sum;
    }
};