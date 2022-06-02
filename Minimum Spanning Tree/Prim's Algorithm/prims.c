#include <stdio.h>
#include <stdlib.h>
#define V 5
#define MAX 10000
struct T{
  int start, dest, weight;
  struct T* next;
};
int visited[V] = {0};
int arraycmp(int arr1[]){
    int allt[V];
    for(int i=0; i < V;i++) allt[i] = 1;
    for(int i=0; i < V;i++) if (allt[i] != arr1[i]) return 0;
    return 1;
}
struct T* push(struct T** head, int start,int dest,int weight){
  struct T* new = (struct T*)malloc(sizeof(struct T));
  new->start = start, new->dest = dest, new->weight = weight,new->next = *head;
  *head = new;
  return new;
}
struct T* retEdge(int graph[V][V],struct T** head){
  int u,v,weight = MAX;
  for(int i=0; i < V;i++){
    for(int j=0; j < V;j++){
      if (visited[i] && !visited[j] && graph[i][j] != 0 && graph[i][j] < weight)
       u = i, v = j,weight = graph[i][j];
  }}struct T* edge = push(head,u,v,weight);
  return edge;
}
void primsMST(struct T** head,int graph[V][V],int start){
  visited[start] = 1;
  while(!arraycmp(visited)){
    struct T* edge = retEdge(graph,head);
    visited[edge->dest] = 1;
  }
}
void printStack(struct T* head){
  printf("\nEdge \tWeight\n");
  while(head){
    printf("%d - %d\t%d\n",head->start,head->dest,head->weight);
    head = head->next;
  }
}
int main() {
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
  struct T* head = NULL;
  primsMST(&head,graph,0);
  printf("Prim's MST is :");
  printStack(head);
  return 0;
}
