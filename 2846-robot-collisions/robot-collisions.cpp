class Solution {
public:
    struct Robot {
        int pos, health, dir, idx;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> v(n);

        for(int i = 0; i < n; i++) {
            v[i] = {positions[i], healths[i], directions[i] == 'R', i};
        }

        sort(v.begin(), v.end(), [](Robot &a, Robot &b) {
            return a.pos < b.pos;
        });

        stack<Robot> st;
        vector<pair<int,int>> ans;

        for(int i = 0; i < n; i++) {
            if(v[i].dir == 1) {
                st.push(v[i]);
            } 
            else {
                int currHealth = v[i].health;

                while(!st.empty() && currHealth > st.top().health) {
                    currHealth--;
                    st.pop();
                }

                if(st.empty()) {
                    if(currHealth > 0)
                        ans.push_back({currHealth, v[i].idx});
                } 
                else {
                    if(currHealth == st.top().health) {
                        st.pop();
                    } 
                    else {
                        Robot top = st.top(); st.pop();
                        top.health--;
                        if(top.health > 0) st.push(top);
                    }
                }
            }
        }

        while(!st.empty()) {
            ans.push_back({st.top().health, st.top().idx});
            st.pop();
        }

        sort(ans.begin(), ans.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> res;
        for(auto &p : ans) res.push_back(p.first);
        return res;
    }
};