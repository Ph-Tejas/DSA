class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astroids) {
        vector<int>ans;
        int n=astroids.size();
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(astroids[i]>0){
                dq.push_back(astroids[i]);
            }
            else{
                if(dq.empty()){
                    ans.push_back(astroids[i]);
                }
                else{
                    if(dq.back()>abs(astroids[i])){
                        continue;
                    }
                    else if(dq.back()<abs(astroids[i])){
                        while(!dq.empty() && dq.back()<abs(astroids[i])){
                            dq.pop_back();
                        }
                        i--;
                        
                    }
                    else{
                        dq.pop_back();
                    }
                }
            }
        }
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};