#User function Template for python3

class Solution:

    def isSafe(self, i, j, mat, n):
        # Check this row on the left side
        for col in range(j):
            if mat[i][col] == 1:
                return False

        # Check the upper diagonal on the left side
        row, col = i, j
        while row >= 0 and col >= 0:
            if mat[row][col] == 1:
                return False
            row -= 1
            col -= 1

        # Check the lower diagonal on the left side
        row, col = i, j
        while row < n and col >= 0:
            if mat[row][col] == 1:
                return False
            row += 1
            col -= 1

        return True

    def solve(self, n, col, mat, result):
        # If all queens are placed, add the solution to result
        if col == n:
            v = []
            for i in range(n):
                for j in range(n):
                    if mat[i][j] == 1:
                        v.append(j + 1)  # 1-based row index for the solution
            result.append(list(v))
            return

        # Try placing queen in all rows one by one in current column
        for i in range(n):
            if self.isSafe(i, col, mat, n):
                mat[i][col] = 1  # Place queen
                self.solve(n, col + 1, mat, result)  # Recur to place the rest
                mat[i][col] = 0  # Backtrack: remove queen from mat[i][col]

    def nQueen(self, n):
        # Initialize n x n board with 0's
        mat = [[0 for _ in range(n)] for _ in range(n)]
        result = []
        self.solve(n, 0, mat, result) 
        result.sort()# Start solving from column 0
        return result

        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        ans = ob.nQueen(n)
        if(len(ans) == 0):
            print("-1")
        else:
            for i in range(len(ans)):
                print("[",end="")
                for j in range(len(ans[i])):
                    print(ans[i][j],end = " ")
                print("]",end = " ")
            print()
                
# } Driver Code Ends
