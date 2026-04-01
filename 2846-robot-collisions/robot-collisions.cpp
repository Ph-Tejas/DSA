class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>>v;
        int n=positions.size();
        int charc;
        for(int i=0;i<n;i++){
            if(directions[i]=='L')charc=0;
            else charc=1;
            v.push_back({positions[i],healths[i],charc,i});
        }
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        vector<pair<int,int>>ans;
        stack<pair<int,int>>st;

        for(int i=0;i<n;i++){
            if(v[i][2]==0){
                if(st.empty()){
                
                    ans.push_back({v[i][1],v[i][3]});
                }
                else{
                    while((!st.empty()) && v[i][1]>st.top().first){
                        v[i][1]-=1;
                        st.pop();
                    }
                    if(st.empty()){
                        if(v[i][1]!=0){
                            ans.push_back({v[i][1],v[i][3]});
                            
                        }
                    }
                    else{
                        if(v[i][1]==st.top().first){
                            st.pop();
                            continue;
                        }
                        if(v[i][1]!=0){
                            int temp=st.top().first;
                            int ind=st.top().second;
                            
                            temp-=1;
                            st.pop();
                            if(temp!=0){
                                st.push({temp,ind});
                            }

                        }

                    }
                }
            }
            else{
                st.push({v[i][1],v[i][3]});
            }

        }
        while(!st.empty()){
            ans.push_back({st.top().first,st.top().second});
            st.pop();
        }
        sort(ans.begin(),ans.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });
        vector<int>fin;
        for(int i=0;i<ans.size();i++){
            fin.push_back(ans[i].first);
        }
        return fin;

    }
};