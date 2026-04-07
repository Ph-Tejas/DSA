class Robot {
public:
    int dir;
    vector<string>direction;
    vector<vector<int>>grid;
    int x,y;
    int n,m;
    int cycle;
    Robot(int w, int h) {
        cycle=(w+w+h+h)-4;
        
        direction={"East","North","West","South"};
        dir=0;
        x=0,y=0;
        n=h,m=w;

        grid.resize(h,vector<int>(w));
    }
    
    void step(int num) {
        int to_zero=0;

        if(dir==0){
            to_zero=(m-x-1)+(n-1)+(m-1)+(n-1);
        }
        else if(dir==1){
            to_zero=(n-y-1)+(m-1)+(n-1);
        }
        else if(dir==2){
            to_zero=(x)+(n-1);
        }
        else if(dir==3){
            to_zero=(y);
        }
        if(num>to_zero){
            num-=to_zero;
            x=0;
            y=0;
            dir=3;
        }
        if(num>=(cycle)&&x==0&&y==0){
            num%=cycle;
            dir=3;
        }
        while(num>0){
            if(dir==0){
                if(m-x-1<=num){
                    if(x==m-1){
                        dir++;
                        dir%=4;
                        continue;

                    }
                    num-=(m-x-1);
                    x=m-1;

                }
                else{
                    
                    x+=num;
                    num=0;
                }
            }
            else if(dir==1){
                if(n-y-1<=num){
                    if(y==n-1){
                        dir++;
                        dir%=4;
                        continue;

                    }
                    num-=(n-y-1);
                    y=n-1;

                }
                else{
                    

                    y+=num;
                    num=0;
                }
            }
            else if(dir==2){
                if(x<=num){
                    if(x==0){
                        dir++;
                        dir%=4;
                        continue;

                    }
                    num-=x;
                    x=0;

                }
                else{
                    
                    x-=num;
                    num=0;
                }
            }
            else if(dir==3){
                if(y<=num){
                    if(y==0){
                        dir++;
                        dir%=4;
                        continue;

                    }
                    num-=y;
                    y=0;

                }
                else{
                    
                    y-=num;
                    num=0;
                }
            }
        }
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return direction[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */