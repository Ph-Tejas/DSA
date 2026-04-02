class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }

        bool flag=false;
        int prev=-1;
        int ct=0;
        while(!mp.empty()){
            if(!flag){
                auto curr=mp.end();
                curr--;
                prev=(*curr).first;
                mp[prev]--;
                if(mp[prev]==0)mp.erase(prev);
                flag=true;
                ct++;
                if(ct==groupSize){
                    ct=0;
                    flag=0;

                }
            }
            else{
                if(mp.find(prev-1)!=mp.end()){
                    mp[prev-1]--;
                    
                    if(mp[prev-1]==0)mp.erase(prev-1);
                    prev--;
                    ct++;
                    if(ct==groupSize){
                    ct=0;
                    flag=0;

                }

                }
                else return false;

            }

        }
        return true;
    }
};