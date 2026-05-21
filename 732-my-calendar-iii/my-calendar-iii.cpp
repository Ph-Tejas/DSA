class MyCalendarThree {
public:
    vector<pair<int,int>>ranges;
    vector<int>ct;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        endTime--;
        
        vector<pair<int,int>>r;
        vector<int>c;
        if(ranges.empty()){
            ranges.push_back({startTime,endTime});
            ct.push_back(1);
            return 1;
        }
        int ans=1;
        bool flag=false;
        for(int i=0;i<ranges.size();i++){
            int rs=ranges[i].first;
            int re=ranges[i].second;
            if(flag){
                r.push_back(ranges[i]);
                c.push_back(ct[i]);
                ans=max(ans,ct[i]);
                continue;
            }
            if(rs>endTime){
                // cout<<1;
                r.push_back({startTime,endTime});
                c.push_back(1);
                r.push_back(ranges[i]);
                c.push_back(ct[i]);
                ans=max(ans,ct[i]);

                flag=true;
            }
            else if(rs>startTime && rs<=endTime && re>=endTime){
                // cout<<2;
                r.push_back({startTime,rs-1});
                c.push_back(1);
                r.push_back({rs,endTime});
                c.push_back(ct[i]+1);
                ans=max(ans,ct[i]+1);
                if(endTime!=re){
                    r.push_back({endTime+1,re});
                    c.push_back(ct[i]);
                    ans=max(ans,ct[i]);
                }
                flag=true;
            }
            else if(rs>startTime && re<endTime){
                // cout<<3;
                r.push_back({startTime,rs-1});
                c.push_back(1);
                r.push_back({rs,re});
                c.push_back(ct[i]+1);

                ans=max(ans,ct[i]+1);
                startTime=re+1;

            }
            else if(rs<=startTime && startTime<=re && re>=endTime){
                // cout<<4;
                if(rs!=startTime){
                    r.push_back({rs,startTime-1});
                    c.push_back(ct[i]);

                    ans=max(ans,ct[i]);
                }
                r.push_back({startTime,endTime});
                c.push_back(ct[i]+1);

                ans=max(ans,ct[i]+1);
                if(re!=endTime){
                    r.push_back({endTime+1,re});
                    c.push_back(ct[i]);

                    ans=max(ans,ct[i]);
                }
                flag=true;

            }
            else if(rs<=startTime && startTime<=re && re<endTime){
                // cout<<5;
                if(rs!=startTime){
                    r.push_back({rs,startTime-1});
                    c.push_back(ct[i]);

                    ans=max(ans,ct[i]);
                }
                r.push_back({startTime,re});
                c.push_back(ct[i]+1);
                ans=max(ans,ct[i]+1);
                startTime=re+1;

            }
            else{
                r.push_back(ranges[i]);
                c.push_back(ct[i]);
                ans=max(ans,ct[i]);
            }
            
            

        }
        r.push_back({startTime,endTime});
        c.push_back(1);
        ranges=move(r);
        ct=move(c);
        return ans;




    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */