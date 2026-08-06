class Solution {
public:

    int longestBeautifulSubstring(string word) {
        int n=word.size();
        int i=0;
        char prev='.';
        int ans=0;
        for(int j=0;j<n;j++){
            // cout<<i<<" "<<j<<endl;
            if(word[j]=='a'){
                if(prev!='.'&&prev!='a'){
                    prev='.';
                    if(i==j){
                        i++;
                        continue;
                    }
                    i=j;        
                    j--;
                }
                else prev='a';
            }
            else if(word[j]=='e'){
                if(prev!='a'&&prev!='e'){
                    prev='.';
                    if(i==j){
                        i++;
                        continue;    
                    }
                    i=j;        
                    j--;
                }
                else prev='e';

            }
            else if(word[j]=='i'){
                if(prev!='i'&&prev!='e'){
                    prev='.';
                    if(i==j){
                        i++;
                        continue;    
                    }
                    i=j;        
                    j--;
                }
                else prev='i';
            }
            else if(word[j]=='o'){
                if(prev!='o'&&prev!='i'){
                    prev='.';
                    if(i==j){
                        i++;
                        continue;    
                    }
                    i=j;        
                    j--;
                }
                else prev='o';
            }
            else if(word[j]=='u'){
                if(prev!='o'&&prev!='u'){
                    prev='.';
                    if(i==j){
                        i++;
                        continue;    
                    }
                    i=j;        
                    j--;
                }
                else prev='u';
            }

            if(prev=='u'){
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};