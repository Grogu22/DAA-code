## Bellman-Ford algorithm
### Algorithm :
```
function bellmanFord(G, S)
  for each vertex V in G
    distance[V] <- infinite
      previous[V] <- NULL
  distance[S] <- 0

  repeat the following steps for |V|-1 times				
    for each edge (U,V) in G
      tempDistance <- distance[U] + edge_weight(U, V)
      if tempDistance < distance[V]
        distance[V] <- tempDistance
        previous[V] <- U

  for each edge (U,V) in G
    If distance[U] + edge_weight(U, V) < distance[V}
      Error: Negative Cycle Exists

  return distance[], previous[]
```
### Graph :
<img width="210" alt="image" src="https://user-images.githubusercontent.com/83173038/174434118-2f1726da-700d-4ece-9c01-d7fa44648de3.png">
