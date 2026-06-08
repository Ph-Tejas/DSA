class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ct = 0;
        multiset<int> st;
        for (int i = n - 1; i > -1; i--) {
            st.insert(people[i]);
        }
        while (!st.empty()) {
            auto it1 = st.end();
            it1--;
            int val = (*it1);
            st.erase(it1);
            ct++;
            if (st.empty())
                break;
            auto it2 = st.upper_bound(limit - val);

            if (it2 != st.begin()) {
                --it2;
                st.erase(it2);
            }
        }

        return ct;
    }
};