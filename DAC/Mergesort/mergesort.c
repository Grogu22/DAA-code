#include <stdio.h>
#include <time.h>
#define MAX 100
#define inf 10000
void printArray(int *arr, int n){
  printf("Array elements are : ");
  for(int i=0;i<n; i++) printf("%d ",arr[i]);
  printf("\n");
}
void merge(int *arr, int l,int m,int r){
  int n1 = m - l + 1;
  int n2 = r - m;
  int a[n1 + 1],b[n2 + 1];
  for(int i=0;i < n1;i++) a[i] = arr[l + i];
  for(int j=0;j < n2;j++) b[j] = arr[m + j + 1];
  a[n1] = inf;b[n2] = inf;
  int i = 0,j = 0;
  for(int k = l;k<= r;k++){
    if (a[i] < b[j]){
      arr[k] = a[i];
      i++;
    }else{
      arr[k] = b[j];
      j++;
    }
  }
}
void mergeSort(int *arr,int l,int r){
  if (l<r){
    int m = l + (r - l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);}
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
  mergeSort(arr,0,n-1);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Sorted elements after Merge sort are :\n");
  printArray(arr,n);
  printf("Time taken for for merge sort algorithm is : %lf seconds \n",time_spent);
  return 0;
}
