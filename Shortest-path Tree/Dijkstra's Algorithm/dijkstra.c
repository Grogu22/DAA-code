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
struct AdjListNode pr[1000];
int size = -1;
void enQue(int dest, int weight){
  size++;
  pr[size].dest = dest, pr[size].weight = weight;
}
int peek(){
 int minp = INT_MAX, ind = -1;
 for(int i=0; i <= size; i++){
     if(pr[i].weight == minp && ind > -1 && pr[ind].dest > pr[i].dest){ minp = pr[i].weight, ind = i;}
     else if(minp > pr[i].weight) { minp = pr[i].weight, ind = i;}
 }return ind;
}
void deQue(){
  if(size == -1) return;
  int ind = peek();
  for(int i = ind; i < size; i++) pr[i] = pr[i+1];
  size--;
}
void Dijkstra(struct Graph* graph,int s,int vertices[]){
  enQue(graph->array[s].head->dest,graph->array[s].head->dest);
  vertices[s] = 0;
  while(size != -1){
    struct AdjListNode* node = graph->array[pr[peek()].dest].head;
    deQue();
    struct AdjListNode* temp = node->next;
    while(temp){
      if (vertices[temp->dest] > vertices[node->dest] + temp->weight){
        //printf("%d %d %d node->dest:%d temp->dest:%d\n",vertices[temp->dest],vertices[node->dest],temp->weight,node->dest, temp->dest);
        //ShortestpathTree(vertices,graph->V);
        vertices[temp->dest] = vertices[node->dest] + temp->weight;
        enQue(temp->dest, temp->weight);
      }
      temp = temp->next;
    }
  }
}
struct AdjListNode* newAdjListNode(int dest, int weight){
  struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  new->next = NULL, new->dest = dest, new->weight = weight;
  return new;
}
struct Graph* createGraph(int V,int vertices[]){
  struct Graph* graph = (struct Graph*)malloc(V * sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct Adjlist*)malloc(V* sizeof(struct Adjlist));
  for(int i=0; i < V;i++) {graph->array[i].head = newAdjListNode(i, 0);vertices[i] = inf;}
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
void ShortestpathTree(int vertices[],int V){
  printf("Vertex   Distance from Source\n");
  for(int i=0; i < V; i++) printf("%d \t\t %d\n", i, vertices[i]);printf("\n");
}
int main() {
  int V = 9;
  int vertices[V];
  struct Graph* graph = createGraph(V, vertices);
  addEdge(graph,0,1,4,1);
  addEdge(graph,0,7,8,1);
  addEdge(graph,1,7,11,1);
  addEdge(graph,1,2,8,1);
  addEdge(graph,2,8,2,1);
  addEdge(graph,2,3,7,1);
  addEdge(graph,2,5,4,1);
  addEdge(graph,3,4,9,1);
  addEdge(graph,3,5,14,1);
  addEdge(graph,4,5,10,1);
  addEdge(graph,5,6,2,1);
  addEdge(graph,6,8,6,1);
  addEdge(graph,6,7,1,1);
  addEdge(graph,7,8,7,1);
  printGraph(graph);
  Dijkstra(graph,0,vertices);
  ShortestpathTree(vertices, V);
  return 0;
}
