class Solution {
public:
    // cout
    int eachn;
    int mod=1e9+7;
    vector<long long>powers;

    long long powy(long long a,long long p){
        long long res=1;
        while(true){
            if(p&1){
                res*=a;
                p--;
                res%=mod;
            }
            else{
                if(p==0)return res%mod;
                a*=a;
                a%=mod;
                p/=2;
            }
        }
        return res%mod;
    }
    long long findHash(string &word){
        long long ans=0;
        int sz=word.size();
        for(int i=0;i<sz;i++){
            ans+=(powers[i]*((word[i]-'a')+1))%mod;
            ans%=mod;
        }
        return ans;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        
        eachn=words[0].size();
        if(((long long)eachn*n)>s.size())return {};
        powers.resize(eachn+1);
        int sz=s.size();
        
        unordered_map<int,int>nums;
        for(int i=0;i<eachn+1;i++){
            powers[i]=powy(27,i);
            // cout<<powers[i]<<" ";

        }
        for(int i=0;i<n;i++){
            nums[(findHash(words[i]))]++;
            // cout<<findHash(words[i])<<" ";
        }
        // cout<<endl;

        vector<int>ans;
        string last;
        long long initialHash=0;
        if(eachn!=1)last=s.substr(sz-(eachn-1));
        // cout<<last<<endl;
        if(eachn!=1)initialHash=findHash(last);
        // cout<<initialHash<<endl;
        vector<int>snums(sz-eachn+1);
        for(int i=sz-eachn;i>-1;i--){
            initialHash*=27;
            initialHash%=mod;
            initialHash+=((s[i]-'a')+1);

            initialHash%=mod;
            snums[i]=initialHash;
            initialHash=(initialHash-((long long)(((s[(i+eachn-1)]-'a')+1)*powers[eachn-1])%mod)+mod)%mod;

        }
        sz=snums.size();
        int originalSize=s.size();


        int totalLen = n * eachn;

        for (int i = 0; i + totalLen <= originalSize; i++) {

            bool flag = true;
            unordered_map<int, int> mp = nums;

            for (int j = i; j < i + totalLen; j += eachn) {

                long long curr = snums[j];

                if (mp.find(curr) != mp.end()) {
                    mp[curr]--;

                    if (mp[curr] == 0)
                        mp.erase(curr);

                } else {
                    flag = false;
                    break;
                }
            }

            if (flag && mp.empty()) {
                ans.push_back(i);
            }
        }
        return ans;



        

        
    }
};