    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        
        ans=[]
        q=deque()
        visited=[0]*V
        visited[0]=1
        q.append(0)
        
        while q:
            curr=q.popleft()
            
            ans.append(curr)
            
            for x in adj[curr]:
                
                if visited[x]!=1:
                    q.append(x)
                    visited[x]=1
        
        return ans
