class Solution:
    def result(self,nums,taken,li,ans,n):
        if(len(li)==n):
            ans.append(list(li))
            return
        
        for i in range(n):
            #take the elemetn
         if(taken[i]==0):
            taken[i]=1
            li.append(nums[i])
            self.result(nums,taken,li,ans,n)
            taken[i]=0
            li.pop()


    def permute(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        taken=[0]*n
        li=[]
        ans=[]

        self.result(nums,taken,li,ans,len(nums))
        return ans
        
