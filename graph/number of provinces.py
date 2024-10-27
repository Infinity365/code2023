#User function Template for python3
class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, adj: List[List[int]]) -> List[int]:
        #code here
        que=deque()
        v=len(adj)
        visited=[False]*v
        que.append(0)
        visited[0]=True
        res=[]
        while(que):
            
            curr=que.popleft()
            res.append(curr)
            
            for i in adj[curr]:
                
                if(visited[i]==False):
                    que.append(i)
                    visited[i]=True
        return res

https://www.youtube.com/watch?v=ACzkVtewUYA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=7
