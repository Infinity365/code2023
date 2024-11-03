from collections import deque
class Solution:
    def bfs(self,grid,visited,row,col):
        rNbr = [-1, -1, -1, 0, 0, 1, 1, 1]
        cNbr = [-1, 0, 1, -1, 1, -1, 0, 1]
        que=deque()
        que.append((row,col))
        visited[row][col]=True
        n=len(grid)
        m=len(grid[0])
        while que:
            r,c=que.popleft()
            
            for i in range(8):
                nrow=r+rNbr[i]
                ncol=c+cNbr[i]
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and visited[nrow][ncol]==0 and grid[nrow][ncol]==1):
                    que.append((nrow,ncol))
                    visited[nrow][ncol]=True
        
                
            
    def numIslands(self, grid):
        # code here
        
        r=len(grid)
        c=len(grid[0])
        visited=[[False for _ in range(c)] for _ in range(r)]
        count=0
        for i in range(r):
            for j in range(c):
                
                if(visited[i][j]==0 and grid[i][j]==1):
                    count=count+1
                    self.bfs(grid,visited,i,j)
                    
        return count
