## We will describe BFS in graphs
We implement BFS on the following graph in the code <b>bfs.c</b><br><br>
<img width="360" alt="image" src="https://user-images.githubusercontent.com/83173038/171701357-4d399d77-aced-4d28-afe3-c44ed915c226.png">
### BFS pseudocode
```
BFS(G, s):// Here, G is graph and s is the start node
  let, Q be a queue
  Q.enQue(s)
  mark s as visited
  while(!Q.isEmpty()):
    //Removing node from front of queue whose neighbors will be visited 
    v = Q.deQue()
    //processing all neighbors of v
    for all neighbors w of v in graph G:
      if w is not visited :
        Q.enQue(w)
```
