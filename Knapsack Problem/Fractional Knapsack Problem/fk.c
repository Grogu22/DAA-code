#include <stdio.h>
#include <stdlib.h>
struct item{
  float weight;
  float profit;
  float ratio;
  float x;
  int index;
};
int cmpfnc(const void* a, const void* b) {
  struct item* A = (struct item*)a;
  struct item* B = (struct item*)b;
  return A->ratio > B->ratio ? -1 : 1;
}
int cmp2(const void* a, const void* b){
  struct item* A = (struct item*)a;
  struct item* B = (struct item*)b;
  return A->index - B->index;
}
int main() {
  int n;
  float m,temp, prof = 0;
  printf("Enter number of items :");
  scanf("%d",&n);
  printf("Enter knapsack capacity :");
  scanf("%f",&m);
  temp = m;
  struct item arr[n];
  for(int i = 0; i < n; i++){
    printf("Enter weight of item %d : ",i+1);
    scanf("%f",&arr[i].weight );
    printf("Enter profit of item %d : ",i+1);
    scanf("%f",&arr[i].profit );
    printf("\n");
  }
  for (int i=0; i < n; i++) {
    arr[i].index = i;
    arr[i].ratio = arr[i].profit/ arr[i].weight;
    arr[i].x = 0;
  }
  qsort(arr, n, sizeof(struct item),cmpfnc);
  int i = 0;
  while (m > 0) {
    if(arr[i].weight <= m){
      m -= arr[i].weight;
      arr[i].x = 1;
      prof+= arr[i].profit;
      i++;
    }else{
      arr[i].x = m/arr[i].weight;
      prof+= arr[i].x* arr[i].profit;
      m = 0;
      i++;
    }
  }
  printf("Final table : \n");
  qsort(arr, n, sizeof(struct item),cmp2);
  printf("Item no|Ratio|Profit|Weight\n");
  for(int i=0; i < n;i++){
    printf("%7d|%.3f|%6d|%6d\n",arr[i].index+1,arr[i].ratio,(int)arr[i].profit,(int)arr[i].weight );
  }
  printf("Profit is : %.2f\n",prof);
  printf("Total weight : %.2f\n",temp-m);
  printf("Array of fractions : ");
  for(int i=0; i < n;i++) printf("%f ",arr[i].x);
  return 0;
}
