class Solution:
    def longestCommonPrefix(self, arr, n):
        
        if(n==0):
            return ""
        if(n==1):
            return arr[0]
        # code here
        arr.sort()
        end=min(len(arr[0]),len(arr[n-1]))
        i=0
        while(i<end and arr[0][i]==arr[n-1][i]):
            i+=1
        
        
        if(i>0):
            ans=arr[0][0:i]
            return ans
        else:
            return -1
            
