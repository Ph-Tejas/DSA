class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();

        unordered_set<int>st1;
        unordered_set<int>st2;
        unordered_set<int>new_st1;
        
        
        for(int i=0;i<n;i++){
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