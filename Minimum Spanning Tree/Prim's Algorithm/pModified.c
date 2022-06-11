#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Edge{
  int src, dest, weight;
  struct Edge* next;
};
struct Graph{
  int V, E;
  struct Edge* edge;
};
struct Graph* createGraph(int V, int E){
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V, graph->E = E;
  graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
  return graph;
}
int cmpfnc(const void* a, const void* b){
  struct Edge* A = (struct Edge*)a;
  struct Edge* B = (struct Edge*)b;
  return A->weight > B->weight ? 1 : -1;
}
void push(struct Edge** head, struct Edge ele){
  struct Edge* new = (struct Edge*)malloc(sizeof(struct Edge));
  new->src = ele.src, new->dest = ele.dest, new->weight = ele.weight;
  new->next = (*head);
  (*head) = new;
}
void printStack(struct Edge* head){
  printf("\nEdge \tWeight\n");
  while(head){
    printf("%d - %d\t%d\n",head->src,head->dest,head->weight);
    head = head->next;
  }
}
void prims(struct Graph* graph, int visited[],struct Edge** head){
  visited[graph->edge[0].src] = 1;
  for(int i=0; i < graph->E; i++) if(!(visited[graph->edge[i].src] && visited[graph->edge[i].dest])) {push(head, graph->edge[i]);visited[graph->edge[i].dest] = 1;visited[graph->edge[i].src] = 1;}
}int main() {
  int V= 4, E=5,visited[V];
  memset(visited,0, V * sizeof(int));
  struct Graph* graph = createGraph(V, E);
  int edges[5][3] = {{0, 1, 10},{1, 3, 15},{2, 3, 4},{2, 0, 6},{0, 3, 5}};
  for(int i=0; i < E; i++) graph->edge[i].src = edges[i][0], graph->edge[i].dest = edges[i][1], graph->edge[i].weight = edges[i][2];
  struct Edge* head = NULL;
  qsort(graph->edge, graph->E, sizeof(struct Edge), cmpfnc);
  printf("Src Dest Weight\n");
  for(int i=0; i < E; i++) printf(" %d    %d    %d\n",graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight );
  prims(graph, visited, &head);
  printf("Prim's MST is:");
  printStack(head);
  return 0;
}
