class Solution:

    def result(self,n,target,sum1,ans,li,arr,ind):
        if(sum1==target):
            ans.append(list(li)) // when we use list(li) it creates a new copy of list and that get added if we simply append(li) then the refrense will be added
            return
        if(ind>=n or sum1>target):
            return 
        
        #now we will check if we should pick this element or nto
        if((sum1+arr[ind])<=target):
            sum1+=arr[ind]
            li.append(arr[ind])
            #we could pick same item multiple times so not increasing index
            self.result(n,target,sum1,ans,li,arr,ind) 
            sum1-=arr[ind]
            li.pop()
        self.result(n,target,sum1,ans,li,arr,ind+1) 

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        n=len(candidates)
        ans=[]
        li=[]
        sum1=0
        ind=0
        self.result(n,target,sum1,ans,li,candidates,ind)
        return ans
