class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>freq(26);
        // bool NotPos=true;
        string temp=s;
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        if(temp<=target)return "";
        // if(NotPos)return "";

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        string ans;
        int it=0;
        for(it;it<n;it++){
            if(it<n-1 && freq[target[it]-'a']>0){
                ans.push_back(target[it]);
                freq[target[it]-'a']--;
            }
            else{
                bool flag=true;
                while(flag){
                    int ch=target[it]-'a';
                    ch++;
                    for(ch;ch<26;ch++){
                        if(freq[ch]>0){
                            flag=false;
                            ans.push_back(ch+'a');
                            freq[ch]--;
                            break;
                        }
                    }
                    it--;
                    if(flag){
                        freq[ans.back()-'a']++;
                        ans.pop_back();

                    }
                }
                break;
            }




        }

        for(int i=0;i<26;i++){
            while(freq[i]>0){
                cout<<i;
                freq[i]--;
                ans.push_back(i+'a');
            }
        }
        return ans;




    }
};