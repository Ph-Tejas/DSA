class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        
        dic1={}
        dic2={}
        n=len(nums)
        a=0
        for i in range(n):
            a+=nums[i]
            dic1[a]=i

        a=0
        for i in range(n-1,0,-1):
            a+=nums[i]
            dic2[a]=i

        dic2[0]=n

        ans=10000000
    
        if (x) in dic2:
            ans=min(ans,n-dic2[x])
        for key,value in dic1.items():
            
            k=x-key
            if k in dic2:
                if n-dic2[k]+value+1<=n:
                    ans=min(ans,n-dic2[k]+value+1)




        if ans==10000000:
            return -1
        return ans
        