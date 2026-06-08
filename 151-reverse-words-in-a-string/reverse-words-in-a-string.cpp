class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp;
        int ct=0;
        bool flag=true;
        for(int i=n-1;i>-1;i--){
            if(flag && s.back()==' '){
                s.pop_back();

            }
            else if(s.back()==' '){
                flag=false;
                if(ct==0){
                    temp.push_back(s.back());
                    ct++;
                }
                s.pop_back();
            }
            else {
                flag=false;
                ct=0;

                temp.push_back(s.back());

                s.pop_back();
            }
            
        }
        temp.push_back(' ');
        int i=0;
        int sz=temp.size();
        for(int j=0;j<sz;j++){
            if(temp[j]==' '){
                int k=j-1;
                while(k>i){
                    swap(temp[i],temp[k]);
                    i++;
                    k--;
                
                }
                i=j+1;

            }
        }
        while(temp.back()==' ')temp.pop_back();
        return temp;
        
    }
};