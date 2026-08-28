class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        string ans(n,'.');
        vector<int>freq(26);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int ct=0;
        char ch;
        for(int i=0;i<26;i++){
            if(freq[i]&1){
                ct++;
                ch=i+'a';
            }
        }
        
        
        if(ct>1)return "";
    
        if(ct==1){
            ans[n/2]=ch;
            freq[ch-'a']--;
        }
        string temp=ans;
        int it=0;
        for(int i=25;i>-1;i--){
            for(int j=0;j<freq[i]/2;j++){
                temp[it]=(i+'a');
                temp[n-1-it]=(i+'a');
                it++;
            }
        }
        if(target>=temp)return "";
        
        it=0;
        bool toBe=true;
        for(it;it<n/2;it++){
            int curr=target[it]-'a';
            if(toBe && freq[curr]>0){
                ans[it]=curr+'a';
                ans[n-1-it]=curr+'a';
                freq[curr]-=2;
                if(it==(n/2)-1){
                    if(ans>target)return ans;
                    else{
                        ans[it]='.';
                        ans[n-1-it]='.';
                        freq[curr]+=2;
                        it--;
                        toBe=false;
                    }
                }

            }
            else{
                bool flag=true;
                while(flag){
                    for(int j=(target[it]-'a')+1;j<26;j++){
                        if(freq[j]>0){
                            
                            flag=false;
                            ans[it]=j+'a';
                            ans[n-1-it]=j+'a';
                            freq[j]-=2;
                            break;
                        }
                    }
                    if(flag){

                        it--;
                        freq[ans[it]-'a']+=2;

                    }


                }
                break;
            }
        }
        it++;
        for(int j=0;j<26;j++){
            while(freq[j]>0){
                ans[it]=j+'a';
                ans[n-1-it]=j+'a';
                freq[j]-=2;
                it++;
            }
        }
        return ans;


        



    }
};