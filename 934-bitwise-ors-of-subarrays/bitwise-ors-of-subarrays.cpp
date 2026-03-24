class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(arr[i]);
            for(int j = i-1; j >= 0; j--){
                if((arr[j] | arr[i]) == arr[j]) break;
                arr[j] |= arr[i];
                s.insert(arr[j]);
            }
        }
        return s.size();
    }
};