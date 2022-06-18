#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define inf 9999
struct AdjListNode{
  int dest, weight;
  struct AdjListNode* next;
};
struct Adjlist{
  struct AdjListNode* head;
};
struct Graph{
  int V;
  struct Adjlist* array;
};
struct AdjListNode* newAdjListNode(int dest, int weight){
  struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  new->next = NULL, new->dest = dest, new->weight = weight;
  return new;
}
struct Graph* createGraph(int V,int distance[]){
  struct Graph* graph = (struct Graph*)malloc(V * sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct Adjlist*)malloc(V* sizeof(struct Adjlist));
  for(int i=0; i < V;i++) {graph->array[i].head = newAdjListNode(i, 0);distance[i] = inf;}
  return graph;
}
void addEdge(struct Graph* graph,int src, int dest, int weight, int flag){
  struct AdjListNode* new = newAdjListNode(dest, weight);
  struct AdjListNode* check = graph->array[src].head;
  while (check->next != NULL) check = check->next;
  check->next = new;
  if (flag){
    new = newAdjListNode(src, weight);
    check = graph->array[dest].head;
    while (check->next != NULL) check = check->next;
    check->next = new;
  }
}
void printGraph(struct Graph* graph){
  for(int i=0; i < graph->V;++i){
    printf("\nThe Adjacency list of the head of node %d is:\n",i);
    struct AdjListNode* temp = graph->array[i].head;
    while(temp) {
      printf(" %d-> ",temp->dest);
      temp = temp->next;
    }
  }
  printf("\n");
}
void BellmanFord(struct Graph* graph,int start,int distance[],int previous[]){
  distance[start] = 0;
  for(int i=0; i < graph->V - 1;i++){
    for(int i=0; i < graph->V;i++){
      struct AdjListNode* u = graph->array[i].head;
      struct AdjListNode* v = u->next;
      while(v){
        int tempDistance = distance[u->dest] + v->weight;
        if (tempDistance < distance[v->dest]){
          distance[v->dest] = tempDistance;
          previous[v->dest] = u->dest;
        }
        v = v->next;
      }
    }
  }
  for(int i=0; i < graph->V;i++){
      struct AdjListNode* u = graph->array[i].head;
      struct AdjListNode* v = u->next;
      while(v){
        int tempDistance = distance[u->dest] + v->weight;
        if (tempDistance < distance[v->dest]) {
          printf("Negative cycle exists\n");
          return;
        } v = v->next;
      }
    }
}
void ShortestpathTree(int distance[],int V){
  printf("Vertex   Distance from Source\n");
  for(int i=0; i < V; i++) printf("%d \t\t %d\n", i, distance[i]);printf("\n");
}
int main() {
  int V = 5;
  int distance[V], previous[V];
  memset(previous,-1,V * sizeof(int));
  struct Graph* graph = createGraph(V, distance);
  addEdge(graph,0,1,-1,0);
  addEdge(graph,0,2, 4,0);
  addEdge(graph,1,2, 3,0);
  addEdge(graph,1,3, 2,0);
  addEdge(graph,1,4, 2,0);
  addEdge(graph,3,1, 1,0);
  addEdge(graph,3,2, 5,0);
  addEdge(graph,4,3,-3,0);
  printGraph(graph);
  BellmanFord(graph, 0, distance, previous);
  ShortestpathTree(distance ,V);
  return 0;
}
