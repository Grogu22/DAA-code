## Code:
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
