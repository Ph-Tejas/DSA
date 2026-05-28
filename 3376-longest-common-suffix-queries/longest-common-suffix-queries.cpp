
class Solution {
public:

    long long mod=1e9+7;

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        int n=wordsContainer.size();
        int m=wordsQuery.size();

        vector<long long> power1(1e4+1);
        vector<long long> power2(1e4+1);

        // MINIMAL CHANGE:
        // store only best {size,index}
        map<
            pair<long long,long long>,
            pair<long long,long long>
        > mp;

        // MINIMAL CHANGE:
        // iterative powers faster than powy()
        power1[0]=1;
        power2[0]=1;

        for(int i=1;i<=1e4;i++){
            power1[i]=(power1[i-1]*27)%mod;
            power2[i]=(power2[i-1]*31)%mod;
        }

        long long prev1,prev2;
        long long a1=0,a2=0;

        int mini=INT_MAX;
        int ind=0;

        long long nw1,nw2;

        for(int j=0;j<n;j++){

            int sz=wordsContainer[j].size();

            if(mini>sz){
                mini=sz;
                ind=j;
            }

            prev1=0;
            prev2=0;

            for(int i=sz-1;i>-1;i--){

                a1=((wordsContainer[j][i]-'a')+1)*power1[sz-1-i];
                a2=((wordsContainer[j][i]-'a')+1)*power2[sz-1-i];

                a1%=mod;
                a2%=mod;

                nw1=(a1+prev1)%mod;
                nw2=(a2+prev2)%mod;

                pair<long long,long long> key={nw1,nw2};

                if(mp.find(key)==mp.end()){
                    mp[key]={sz,j};
                }
                else{

                    auto &p=mp[key];

                    if(sz<p.first){
                        p={sz,j};
                    }
                    else if(sz==p.first && j<p.second){
                        p={sz,j};
                    }
                }

                prev1=nw1;
                prev2=nw2;
            }
        }

        vector<int> ans(m);

        for(int j=0;j<m;j++){

            int sz=wordsQuery[j].size();

            prev1=0;
            prev2=0;

            ans[j]=ind;

            for(int i=sz-1;i>-1;i--){

                a1=((wordsQuery[j][i]-'a')+1)*power1[sz-1-i];
                a2=((wordsQuery[j][i]-'a')+1)*power2[sz-1-i];

                a1%=mod;
                a2%=mod;

                nw1=(a1+prev1)%mod;
                nw2=(a2+prev2)%mod;

                pair<long long,long long> key={nw1,nw2};

                if(mp.find(key)!=mp.end()){

                    ans[j]=mp[key].second;
                }
                else{
                    break;
                }

                prev1=nw1;
                prev2=nw2;
            }
        }

        return ans;
    }
};