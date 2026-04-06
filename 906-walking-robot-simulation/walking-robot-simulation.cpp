class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int o=obstacles.size();
        int n=commands.size();
        set<pair<int,int>>st;
        for(int i=0;i<o;i++){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }

        int maxi=0;
        int x=0;
        int y=0;

        int it=0;
        int turn=0;
        int mod=4;
        while(it<n){
            int curr=commands[it];
            if(curr==-2){
                turn-=1;
                turn+=mod;
                turn%=mod;
            }
            else if(curr==-1){
                turn+=1;
                turn+=mod;
                turn%=mod;
            }
            else{
                if(turn==0){
                    pair<int,int>pr;
                    for(int i=0;i<curr;i++){
                        pr={x,y+1};
                        if(st.find(pr)!=st.end()){
                            break;
                        }
                        y++;

                    }
                }
                else if(turn==1){
                    pair<int,int>pr;
                    for(int i=0;i<curr;i++){
                        pr={x+1,y};
                        if(st.find(pr)!=st.end()){
                            break;
                        }
                        x++;

                    }
                    
                }
                else if(turn==2){
                    pair<int,int>pr;
                    for(int i=0;i<curr;i++){
                        pr={x,y-1};
                        if(st.find(pr)!=st.end()){
                            break;
                        }
                        y--;

                    }
                }
                else if(turn==3){
                    pair<int,int>pr;
                    for(int i=0;i<curr;i++){
                        pr={x-1,y};
                        if(st.find(pr)!=st.end()){
                            break;
                        }
                        x--;

                    }
                }
            }
            it++;
            maxi=max(maxi,(x*x)+(y*y));
        }

        return maxi;





    }

};