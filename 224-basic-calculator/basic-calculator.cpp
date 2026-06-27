class Solution {
public:
    int n;
    map<int,int>mp;
    int evaluate(string &s,int sign,int it,int en){
        

        stack<string>st;
        
        bool flag=0;
        int sum=0;
        while(it<en){
            if(s[it]=='('){
                
                sum+=evaluate(s,1,it+1,mp[it]);
                it=mp[it];
            }
            else if(s[it]=='-'){
                if(s[it+1]=='('){
                    sum+=evaluate(s,-1,it+2,mp[it+1]);
                    it=mp[it+1];

                }
                else flag=1;
            
            }
            else if(s[it]>='0' && s[it]<='9'){
                
                string num;
                if(flag){
                    num.push_back('-');
                    flag=0;
                }
                while(it<en && s[it]>='0' && s[it]<='9'){
                    num.push_back(s[it]);
                    it++;

                }
                sum+=stoi(num);
                it--;



            }
            it++;

        }
        sum*=sign;
        return sum;

    }
    int calculate(string s_) {
        s_.insert(s_.begin(),'(');
        s_.push_back(')');
        string s;
        for(int i=0;i<s_.size();i++){
            if(s_[i]==' ')continue;
            s.push_back(s_[i]);
        }
        n=s.size();
        stack<int>brk;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                brk.push(i);

            }
            else if(s[i]==')'){
                mp[brk.top()]=i;
                brk.pop();
            }
        }
        int it=0;
        int sign=1;
        int en=mp[it];
        
        return evaluate(s,sign,it+1,n-1);
        
    }
};