#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>
#define MAX 100
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}
void printArray(int *arr, int n){
  printf("Array elements are : ");
  for(int i=0;i<n; i++)
  printf("%d ",arr[i]);
  printf("\n");
}
int partition(int* arr,int l,int r){
  int x = arr[l];
  int i = l - 1;
  int j = r + 1;
  while(1){
    while(arr[j] > x) 
        j--;
    while(arr[i] < x) 
        i++;
  if (i < j) swap(&arr[i],&arr[j]);
  else return j;
  }
}
void quicksort(int* arr, int l,int r){
  if (l < r){
    int q = partition(arr, l, r);
    quicksort(arr, l, q-1);
    quicksort(arr, q + 1, r);
  }
}
int main() {
  int arr[MAX], n;
  printf("Enter the number of elements in array : ");
  scanf("%d",&n);
  for(int i=0;i <n;i++){
    printf("Enter %dth element : ",i + 1);
    scanf("%d",&arr[i]);
  }
  printArray(arr,n);
  clock_t begin = clock();
  quicksort(arr,0,n-1);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %lf seconds\n", time_spent);
  printf("Sorted elements after quicksort are :\n");
  printArray(arr,n);
  return 0;
}
