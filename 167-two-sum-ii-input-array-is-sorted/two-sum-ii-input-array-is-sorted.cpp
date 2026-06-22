class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int tgt) {
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==tgt){
                return {i+1,j+1};
            }
            if(numbers[i]+numbers[j]>tgt){
                j--;
            }
            if(numbers[i]+numbers[j]<tgt){
                i++;
            }
            
        }
        return {};

    }
};