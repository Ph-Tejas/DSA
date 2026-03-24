class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();

        set<int>st1;
        set<int>st2;
        set<int>new_st1;
        st1.insert(arr[0]);
        st2.insert(arr[0]);
        
        for(int i=1;i<n;i++){
            int curr=arr[i];
            st2.insert(curr);
            new_st1.insert(curr);
            for(auto val:st1){
                new_st1.insert(val|curr);
                st2.insert(val|curr);
            }
            st1=move(new_st1);
        }
        return st2.size();
    }
};