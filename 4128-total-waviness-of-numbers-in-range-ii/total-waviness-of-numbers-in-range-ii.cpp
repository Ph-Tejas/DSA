class Solution {
public:
    int n;
    vector<long long>powy;
    long long LetsDoIt(string &s,int sz,int prev,int tight,int shouldAdd,int didStart,vector<vector<vector<vector<vector<long long>>>>>&dp){
        if(sz==0)return 0;
        if(dp[sz][prev][tight][shouldAdd][didStart]!=-1)return dp[sz][prev][tight][shouldAdd][didStart];
        int curr=s[n-sz]-'0';
        long long ans=0;
        int it=0;
        if(tight){
            for(it;it<min(prev,curr+1);it++){
                
                if(shouldAdd==2){
                    if(it!=curr){
                        ans+=powy[sz-1];
                    }
                    else{
                        if(n-sz+1!=n){
                            
                            string str=s.substr(n-sz+1);
                            long long state=stoll(str);
                            ans+=state+1;
                        }
                        else ans++;
                    }
                }
                ans+=LetsDoIt(s,sz-1,it,(it==curr)?1:0,(didStart==1)?1:0,((didStart)||(!didStart && it!=0))?1:0,dp);
            }
            if(it!=curr+1){
                if(it==prev){
                    ans+=LetsDoIt(s,sz-1,it,(it==curr)?1:0,0,((didStart)||(!didStart && it!=0))?1:0,dp);
                    it++;
                }
                for(it;it<curr+1;it++){
                    if(shouldAdd==1){
                        if(it!=curr){
                            ans+=powy[sz-1];
                        }
                        else{
                            if(n-sz+1!=n){
                                string str=s.substr(n-sz+1);
                                long long state=stoll(str);
                                ans+=state+1;
                            }
                            else ans++;
                        }
                    }
                    ans+=LetsDoIt(s,sz-1,it,(it==curr)?1:0,(didStart==1)?2:0,((didStart)||(!didStart && it!=0))?1:0,dp);
                }
            }
        }
        else{
            curr=9;
            for(it;it<min(prev,curr+1);it++){
                if(shouldAdd==2){
                    ans+=powy[sz-1];
                    
                }
                ans+=LetsDoIt(s,sz-1,it,0,(didStart==1)?1:0,((didStart)||(!didStart && it!=0))?1:0,dp);
            }
            if(it!=curr+1){
                if(it==prev){
                    ans+=LetsDoIt(s,sz-1,it,0,0,((didStart)||(!didStart && it!=0))?1:0,dp);
                    it++;
                }
                for(it;it<curr+1;it++){
                    if(shouldAdd==1){
                        ans+=powy[sz-1];
                    }
                    ans+=LetsDoIt(s,sz-1,it,0,(didStart==1)?2:0,((didStart)||(!didStart && it!=0))?1:0,dp);
                }
            }
        }
        return dp[sz][prev][tight][shouldAdd][didStart]=ans;
            



    }
    long long fun(long long num,vector<vector<vector<vector<vector<long long>>>>>&dp){
        string s=to_string(num);
        n=s.size();

        


        int sz=s.size();
        if(n<3)return 1LL*0;

        return LetsDoIt(s,sz,0,1,0,0,dp);





















    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    long long totalWaviness(long long num1, long long num2) {
        powy.push_back(1);
        for(int i=0;i<17;i++){
            powy.push_back(powy[i]*10);
        }
        
    //sz=16, prev= 10, tight=2, shouldAdd=3, didStart=2;
        vector<vector<vector<vector<vector<long long>>>>>dp1,dp2;
        dp1.resize(20,vector<vector<vector<vector<long long>>>>(10,vector<vector<vector<long long>>>(2,vector<vector<long long>>(3,vector<long long>(2,-1)))));
        
        dp2.resize(20,vector<vector<vector<vector<long long>>>>(10,vector<vector<vector<long long>>>(2,vector<vector<long long>>(3,vector<long long>(2,-1)))));
        return fun(num2,dp1)-fun(num1-1,dp2);
    }
};