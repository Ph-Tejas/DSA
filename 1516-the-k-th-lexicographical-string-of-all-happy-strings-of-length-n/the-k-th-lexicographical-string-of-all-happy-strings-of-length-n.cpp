class Solution {
public:
    string getHappyString(int n, int k) {
        if(k>3*(1<<(n-1)))return "";
        string ans;
        char prev;
        if(k<=(1<<(n-1))){
            ans.push_back('a');
            prev='a';

        }
        else if(k<=2*(1<<(n-1))){
            ans.push_back('b');
            k-=((1<<(n-1)));
            prev='b';
        }
        else {
            ans.push_back('c');
            k-=2*((1<<(n-1)));
            prev='c';
        }
        for(int i=1;i<n;i++){
            if(prev=='a'){
                if(k<=(1<<(n-1-i))){
                    ans.push_back('b');
                    
                }
                else{
                    ans.push_back('c');
                    k-=(1<<(n-1-i));
                }


            }
            else if(prev=='b'){
                if(k<=(1<<(n-1-i))){
                    ans.push_back('a');
                    
                }
                else{
                    ans.push_back('c');
                    k-=(1<<(n-1-i));
                }
            }
            else{
                if(k<=(1<<(n-1-i))){
                    ans.push_back('a');
                    
                }
                else{
                    ans.push_back('b');
                    k-=(1<<(n-1-i));
                }
            }
            prev=ans.back();

        }
        return ans;



    }
};