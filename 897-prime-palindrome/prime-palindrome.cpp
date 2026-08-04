class Solution {
public:
    bool isP(string s){
        int n=stoi(s);

        for(int i=2;i<=sqrt(n)+1;i++){
            
            if(n%i==0){
                
                return false;
            }
        }
        return true;
    }
    int primePalindrome(int n) {
        if(n<=2)return 2;
        if(n==3)return 3;
        if(n<=5)return 5;
        if(n<=7)return 7;
        if(n<=11)return 11;
        int init=1;
        string ref=to_string(init);
        int sz=ref.size();

        while(init){
            string num=to_string(init);
            string rev=num;
            reverse(rev.begin(),rev.end());
            for(int i=0;i<=9;i++){
                string mid;
                mid.push_back('0'+i);
            
                string overall=num+mid+rev;
                
                if(overall.size()<sz)break;

                if(stoll(overall)<n){
                    
                    continue;
                }

                if(isP(overall)){
                    return stoi(overall);
                }
            }

            init++;





        }
        return -1;
        
    }
};