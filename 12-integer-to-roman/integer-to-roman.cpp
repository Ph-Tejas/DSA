class Solution {
public:
    string intToRoman(int num) {
        string s=to_string(num);
        int n=s.size();
        string str="IVXLCDM";
        reverse(s.begin(),s.end());
        string ans;
        for(int i=n-1;i>-1;i--){
            if(i==3){

                
                for(int it=0;it<s[i]-'0';it++){
                    ans.push_back('M');
                }
            
            }
            else{
                int a=((i+1)*2)-2;
                int b=((i+1)*2)-1;
                int c=((i+1)*2);
                if(s[i]<'4'){
                    for(int it=0;it<s[i]-'0';it++){
                        ans.push_back(str[a]);
                    }
                }
                else if(s[i]=='4'){
                    
                    ans.push_back(str[a]);

                    ans.push_back(str[b]);

                }
                else if(s[i]=='9'){
                    ans.push_back(str[a]);

                    ans.push_back(str[c]);
                }
                else{
                    ans.push_back(str[b]);
                    for(int it=0;it<s[i]-'5';it++){
                        ans.push_back(str[a]);
                    }
                }




            }
        }
        return ans;
    }
};