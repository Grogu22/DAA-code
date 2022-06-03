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
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
  return graph;
}
void makeSet(int parent[],int N){
  for(int i=0; i < N; i++) parent[i] = i;
}
int find(int parent[],int i){
  if (parent[i] != i) parent[i] = find(parent, parent[i]);
  return parent[i];
}
void Union(int parent[],int rank[], int x, int y) {
  int xset = find(parent, x);
  int yset = find(parent, y);
  if (xset == yset) return;
  if (rank[xset] < rank[yset]) parent[xset] = yset;
  else if (rank[xset] > rank[yset]) parent[yset] = xset;
  else{
    parent[yset] = xset;
    rank[xset] = rank[xset] + 1;
  }
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
void kruskal(struct Graph* graph, int parent[], int rank[], struct Edge** head){
 makeSet(parent, graph->V);
 for(int i=0; i < graph->E; i++) if (find(parent, graph->edge[i].src) != find(parent, graph->edge[i].dest)){
   push(head, graph->edge[i]);
   Union(parent, rank, graph->edge[i].src, graph->edge[i].dest);
 }
}
void printStack(struct Edge* head){
  printf("\nEdge \tWeight\n");
  while(head){
    printf("%d - %d\t%d\n",head->src,head->dest,head->weight);
    head = head->next;
  }
}

int main() {
  int V= 4, E = 5,parent[V],rank[V];
  memset(rank, 0, V* sizeof(int));
  struct Graph* graph = createGraph(V, E);
  int edges[5][3] = {{0, 1, 10},{1, 3, 15},{2, 3, 4},{2, 0, 6},{0, 3, 5}};
  for(int i=0; i < E; i++) graph->edge[i].src = edges[i][0], graph->edge[i].dest = edges[i][1], graph->edge[i].weight = edges[i][2];
  struct Edge* head = NULL;
  qsort(graph->edge, graph->E, sizeof(struct Edge), cmpfnc);
  printf("Edge source Edge destination Edge weight\n");
  for(int i=0; i < E; i++) printf("      %d        \t%d \t\t  %d\n",graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight );
  printf("Kruskal's MST is:");
  kruskal(graph, parent, rank, &head);
  printStack(head);
  return 0;
}
