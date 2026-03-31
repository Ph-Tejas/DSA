class Solution {
public:
    string generateString(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();
        string ans(n+m-1,'.');
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    if(ans[i+j]=='.'){
                        ans[i+j]=str2[j];
                    }
                    else{
                        if(ans[i+j]!=str2[j]){
                            return "";

                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                int last=-1;
                int lasta=-1;
                for(int j=0;j<m;j++){

                    if(ans[i+j]=='.'&&str2[j]!='a'){
                        last=j;
                    }
                    if(ans[i+j]=='.'&&str2[j]=='a'){
                        lasta=j;
                    }
                    if(ans[i+j]!='.'&&ans[i+j]!=str2[j]){
                        last=-1;
                        lasta=-1;
                        break;
                    }

                }
                for(int j=0;j<m;j++){
                    if(ans[i+j]=='.'){
                        if(j==last){
                            ans[i+j]='a';
                            break;
                        }
                        if(last==-1){
                            if(j==lasta){
                                ans[i+j]='b';
                                break;
                            }
                        }

                    

                    }
                    else{
                        if(ans[i+j]!=str2[j]){
                            break;
                        }
                        else{
                            if(j==m-1){
                                return "";
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n+m-1;i++){
            if(ans[i]=='.')ans[i]='a';
        }
        return ans;



    }
};