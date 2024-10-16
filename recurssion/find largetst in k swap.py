#User function Template for python3
class Solution:
    def swap(self, s, i, j):
        # Swap the characters at index i and j and return the new string
        return s[:i] + s[j] + s[i+1:j] + s[i] + s[j+1:]

    # Function to find the largest number after k swaps
    def sol(self, s, k, ans, ind):
        n = len(s)
        if k == 0 or ind == n:
            return
        
        # Find the maximum digit in the substring starting from the current index
        maxnum = max(s[ind:])
        
        # If the current digit is already the maximum, proceed to the next index
        if maxnum == s[ind]:
            self.sol(s, k, ans, ind + 1)
        else:
            # Try swapping with all occurrences of the maximum digit
            for i in range(ind + 1, n):
                if s[i] == maxnum:
                    # Swap the digits at ind and i
                    s1 = self.swap(s, ind, i)
                    # Update the answer if the new number is larger
                    if ans[0] < s1:
                        ans[0] = s1
                    # Recursively find the next largest number with remaining swaps
                    self.sol(s1, k - 1, ans, ind + 1)

    def findMaximumNum(self, s, k):
        # Initialize ans to store the maximum number found
        ans = [s]
        # Start recursion from index 0 with k swaps allowed
        self.sol(s, k, ans, 0)
        # Return the largest number found
        return ans[0]




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        k = int(input())
        s = input()
        ob=Solution()
        print(ob.findMaximumNum(s,k))

# } Driver Code Ends
