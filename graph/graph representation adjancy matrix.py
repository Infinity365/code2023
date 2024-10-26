def add_edge(adj,i,j):
    adj[i].append(j)
    adj[j].append(i)

def display(adj):
    
    for i in range(len(adj)):
        print(f"{i}:", end=" ")
        for j in adj[i]:
            print(j, end=" ")
        print()
            
V = 4
adj = [[] for _ in range(V)]

# Now add edges one by one
add_edge(adj, 0, 1)
add_edge(adj, 0, 2)
add_edge(adj, 1, 2)
add_edge(adj, 2, 3)

print("Adjacency List Representation:")
display(adj)


https://www.geeksforgeeks.org/adjacency-list-meaning-definition-in-dsa/
