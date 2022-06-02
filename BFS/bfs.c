#include<stdio.h>
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
struct QNode{
  struct AdjListNode* k;
  struct QNode* next;
};
struct AdjListNode* newAdjListNode(int dest){
  struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  new->next = NULL;
  new->dest = dest;
  return new;
}
struct Graph* createGraph(int V){
  struct Graph* graph = (struct Graph*)malloc(V * sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct Adjlist*)malloc(V* sizeof(struct Adjlist));
  for(int i=0; i < V;i++) graph->array[i].head = newAdjListNode(i);
  return graph;
}
void enQue(struct QNode** head, struct QNode** tail,struct AdjListNode* ele){
  struct QNode* new = (struct QNode*)malloc(sizeof(struct QNode));
  new->k = ele;
  new->next = NULL;
  if ((*head) == NULL){
    (*head) = (*tail) = new;
    return;
  }(*tail)->next = new;
  (*tail) = new;
}
struct AdjListNode* deQue(struct QNode** head, struct QNode** tail){
  if (*head == NULL) return NULL;
  struct QNode* bull = *head;
  struct AdjListNode* temp = (*head)->k;
  (*head) = bull->next;
  return temp;
}
void puchkiBFS(struct QNode** head1,struct QNode** tail1,struct QNode** head2,struct QNode** tail2,int visited[],struct Graph* graph, int v){
  struct AdjListNode* temp = graph->array[v].head;
  visited[temp->dest] = 1;
  enQue(head1,tail1,temp);
  while (*head1) {
     struct AdjListNode* samp = deQue(head1,tail1);
     printf(" %d->",samp->dest);
     enQue(head2,tail2,samp);
     struct AdjListNode* w = graph->array[samp->dest].head;
     while(w){
       if (!visited[w->dest]) enQue(head1,tail1,w);
       visited[w->dest] = 1;
       w = w->next;
     }//printQueue(*head1);
  }
}
void BFS(struct QNode** head1,struct QNode** tail1,struct QNode** head2,struct QNode** tail2,int visited[],struct Graph* graph, int v){
  puchkiBFS(head1,tail1,head2,tail2,visited,graph,v);
  for(int i = 0;i < graph->V;i++) if (!visited[i]) puchkiBFS(head1,tail1,head2,tail2,visited,graph,i);
}
void printQueue(struct QNode* head1){
  struct QNode* temp = head1;
  printf("\nQueue elements : ");
  while(temp){
    printf(" %d-> ",temp->k->dest);
    temp = temp->next;
  }printf("\n");
}
// if flag is non-zero.. either it is undirected graph.. or biderected
void addEdge(struct Graph* graph, int src, int dest, int flag) {
  struct AdjListNode* new = newAdjListNode(dest);
  struct AdjListNode* check = graph->array[src].head;
  if(graph->array[src].head == NULL){
    new->next = check;
    graph->array[src].head = new;
  }else{
    while (check->next != NULL) check = check->next;
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
  printf("\n");
}
int main() {
  int V = 7;
  struct Graph* graph = createGraph(V);
  addEdge(graph, 0, 4, 0);
  addEdge(graph, 4, 5, 0);
  addEdge(graph, 5, 6, 0);
  addEdge(graph, 1, 3, 0);
  addEdge(graph, 2, 3, 0);
  printGraph(graph);
  int visited[V];
  for(int i=0;i < V;i++) visited[i] = 0;
  struct QNode* head1 = NULL;
  struct QNode* tail1 = NULL;
  struct QNode* head2 = NULL;
  struct QNode* tail2 = NULL;
  printf("BFS is : ");
  BFS(&head1,&tail1,&head2,&tail2,visited,graph,0);
  printQueue(head2);
  return 0;
}
