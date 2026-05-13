class Solution {
public:
    int minPartitions(string n) {
        if(n=="0")return 1;
        if(n=="1")return 1;
        if(n.size()==1)return n[0]-'0';
        for(int i=1;i<n.size();i++){
            if(n[i]<n[i-1])n[i]=n[i-1];
        }
        return n.back()-'0';
    }
};