class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        multiset<long long>st;
        long long m=mass;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            st.insert(asteroids[i]);
        }
        while(!st.empty()){
            auto it=st.upper_bound(m);
            if(it==st.begin())return false;
            it--;
            m+=(*it);
            st.erase(it);
        }
        return true;
        
    }
};