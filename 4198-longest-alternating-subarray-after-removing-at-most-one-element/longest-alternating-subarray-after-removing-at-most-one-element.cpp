class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n=nums.size();
        bool com=false;
        bool sign=0;
        int ans=1;
        int mid=-1;
        int sum=1;
        bool extra=false;
        for(int j=0;j<n-1;j++){
            if((!com)&&nums[j]==nums[j+1])continue;
            if(!com){
                com=true;
                if(nums[j]>nums[j+1]){
                    sign=0;
                }
                else sign=1;
                sum++;
                ans=max(ans,sum);

            }
            else{
                if((nums[j]>nums[j+1]&&sign==1)){
                    sign=0;
                    sum++;
                    ans=max(ans,sum);
                }
                else if((nums[j]<nums[j+1]&&sign==0)){
                    sign=1;
                    sum++;
                    ans=max(ans,sum);
                }
                else{
                    if(j+2==n)break;
                    if(!extra){
                        
                        if((max(nums[j],nums[j+1])>nums[j+2]&&sign==1)){
                            if(nums[j]==nums[j+1])mid=sum-1;
                            else mid=sum-2;
                            sign=0;
                            sum++;
                            j++;
                            ans=max(ans,sum);
                            extra=true;
                        }
                        else if((min(nums[j],nums[j+1])<nums[j+2]&&sign==0)){
                            if(nums[j]==nums[j+1])mid=sum-1;
                            else mid=sum-2;
                            sign=1;
                            sum++;
                            j++;
                            ans=max(ans,sum);
                            extra=true;
                        }
                        else{
                            com=false;
                            sum=1;
                            mid=-1;
                            j--;

                        }
                    }
                    else{
                        sum-=mid;
                        if((max(nums[j],nums[j+1])>nums[j+2]&&sign==1)){
                            if(nums[j]==nums[j+1])mid=sum-1;
                            else mid=sum-2;
                            sign=0;
                            sum++;
                            j++;
                            ans=max(ans,sum);
                        }
                        else if((min(nums[j],nums[j+1])<nums[j+2]&&sign==0)){
                            
                            if(nums[j]==nums[j+1])mid=sum-1;
                            else mid=sum-2;
                            sign=1;
                            sum++;
                            j++;
                            ans=max(ans,sum);
                        }
                        else{
                            com=false;
                            sum=1;
                            mid=-1;
                            j--;
                            extra=false;

                        }

                    }
                    
                }
            }
        }
        return ans;

    }
};