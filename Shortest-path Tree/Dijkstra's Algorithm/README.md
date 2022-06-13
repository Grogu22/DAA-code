## Djisktra's shortest-path algorithm
### Graph :
![image](https://user-images.githubusercontent.com/83173038/173420444-b2d85ce2-eff9-416f-9dec-7172352bb98e.png)
<br>Shortest path for this graph : <br>
```
Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14
```
### Code:
<ul>
  <li>Implementation of Dijkstra's algorithm using array-based priority queue</li>
</ul>
<h3> Algorithm for implementation using priority queue:</h3>
<p><code>1)Initialize distances of all vertices as infinite.</code></p>
<p><code>2) Create an empty minimum priority queue pq.  Every item of pq is a pair (weight, vertex).Priority is based on weight.</code></p>
<p><code>3) Insert source vertex into pq and make its distance as 0.</code></p>
<p><code>4) While pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do following for every vertex v.</code></p>

           // If there is a shorter path to v through u.
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is already there)
  <p><code>5) Print distance array dist[] to print all shortest paths. </code></p>
