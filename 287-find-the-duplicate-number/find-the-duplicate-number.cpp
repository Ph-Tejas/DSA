class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums[0];
        int f=nums[0];
        bool flag=false;
        while(true){
            
            s=nums[s];
            f=nums[f];
            if(!flag)f=nums[f];
            if(s==f && (!flag)){
                s= nums[0];
                flag=true;
            }
            if(s==f && (flag)){
                break;
            }
            
        }
        return s;

         
    }
};