#User function Template for python3


#Function to determine if graph can be coloured with at most M colours such
#that no two adjacent vertices of graph are coloured with same colour.
def issafe(graph,curcol,V,ind,color):
    
    for i in range(V):
        if( graph[i][ind]==1 and color[i]==curcol):
            return False
        
    return True
    
def solve(graph,k,V,ind,color):
    if(ind>=V):
        return True
        
    for i in range(k):
        if(issafe(graph,i,V,ind,color)==True):
            color[ind]=i 
            
            if(solve(graph,k,V,ind+1,color)==True):
                return True
            color[ind]=-1
            
    
def graphColoring(graph, k, V):
    #print(k)
    color=[-1]*V
    ind=0
    if(solve(graph,k,V,ind,color)==True):
        return True
    else:
        return False

    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while (t > 0):
        V = int(input())
        k = int(input())
        m = int(input())
        l = [int(x) for x in input().strip().split()]
        graph = [[0 for i in range(V)] for j in range(V)]
        cnt = 0
        for i in range(m):
            graph[l[cnt] - 1][l[cnt + 1] - 1] = 1
            graph[l[cnt + 1] - 1][l[cnt] - 1] = 1
            cnt += 2
        if (graphColoring(graph, k, V) == True):
            print(1)
        else:
            print(0)

        t = t - 1

# } Driver Code Ends
