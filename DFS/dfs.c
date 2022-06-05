#include <stdio.h>
#include <stdlib.h>
struct AdjListNode{
  int dest;
  struct AdjListNode* next;
};
struct Adjlist{
  struct AdjListNode* head;
};
struct Graph{
  int V;
  struct Adjlist* array;
};
struct Node{
  struct AdjListNode* k;
  struct Node* next;
};
struct AdjListNode* newAdjListNode(int dest){
  struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  new->next = NULL;
  new->dest = dest;
  return new;
}
struct Graph* createGraph(int V){
  struct Graph* graph = (struct Graph*)malloc(V* sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct Adjlist*)malloc(V* sizeof(struct Adjlist));
  for(int i=0; i < V;i++) graph->array[i].head = newAdjListNode(i);
  return graph;
}
void push(struct Node** head1, struct AdjListNode* ele){
  struct Node* new = (struct Node*)malloc(sizeof(struct Node));
  new->k = ele;
  new->next = *head1;
  *head1 = new;
}
struct Node* pop(struct Node** head1){
  struct Node* temp = (*head1);
  if (temp != NULL){
    *head1 = temp->next;
    return temp;
  }
  if (*head1 == NULL) printf("Empty stack\n");
}
void DFS(struct Node** head1,int visited[],struct Graph** graph, int v) {
  printf("\nDFS traversal is : ");
  puchkiDFS(head1,visited,graph,v);
  for(int i = 0; i < (*graph)->V; i++) if (!visited[i]) puchkiDFS(head1,visited,graph,i);
}
void puchkiDFS(struct Node** head1,int visited[],struct Graph** graph, int v){
  struct AdjListNode* temp = (*graph)->array[v].head;
  push(head1,temp);
  while (*head1) {
    struct AdjListNode* u = pop(head1)->k;
    if (!visited[u->dest]) printf(" %d-> ",u->dest);
    visited[u->dest] = 1;
    struct AdjListNode* w = (*graph)->array[u->dest].head;
    while(w){
      if (!visited[w->dest]) push(head1,w);
      w = w->next;
    }
  }
}
void addEdge(struct Graph* graph, int src, int dest, int flag){
  struct AdjListNode* new = newAdjListNode(dest);
  struct AdjListNode* check = graph->array[src].head;
  if(graph->array[src].head == NULL){
    new->next = check;
    graph->array[src].head = new;
  }else{
    while(check->next != NULL) check = check->next;
    check->next = new;
  }
  if (flag){
    new = newAdjListNode(src);
    check = graph->array[dest].head;
    if (graph->array[dest].head == NULL){
      new->next = check;
      graph->array[dest].head = new;
    }else{
      while(check->next != NULL) check = check->next;
      check->next = new;
    }
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
}
void printStack(struct Node* head1){
  printf("\nStack Elements : ");
  while(head1){
    printf(" %d-> ",head1->k->dest);
    head1 = head1->next;
  }printf("\n");
}
int main() {
  int V = 7;
  struct Graph* graph = createGraph(V);
  addEdge(graph,0,4,0);
  addEdge(graph,4,5,0);
  addEdge(graph,5,6,0);
  addEdge(graph,1,3,0);
  addEdge(graph,2,3,0);
  printGraph(graph);
  int visited[V];
  for(int i=0; i < V;i++) visited[i] = 0;
  struct Node* head1 = NULL;
  DFS(&head1,visited,&graph,0);
  printStack(head1);
  return 0;
}
