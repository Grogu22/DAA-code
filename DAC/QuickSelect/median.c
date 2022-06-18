#include <stdio.h>
#define MAX 100
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}
int partition(int *arr, int l, int r){
  int x = arr[r], i = l - 1;
  for(int j=l; j < r;j++){
    if(arr[j] <= x){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }swap(&arr[i+1],&arr[r]);
  return i + 1;
}
int select(int *arr, int l, int r, int k){
  if (l == r) return arr[l];
  int pivotIndex = partition(arr, l, r);
  if (k == pivotIndex) return arr[k];
  else if(k < pivotIndex) return select(arr,l,pivotIndex - 1, k);
  else return select(arr,pivotIndex + 1,r, k);
}
int main(){
  //int arr[] = {12, 3, 5, 7, 4, 19, 26};
  int arr[] = {12, 3, 5, 7, 4, 20, 19, 26};
  int n = sizeof(arr)/ sizeof(arr[0]);
  (n % 2 == 0) ? printf("median = %.2f\n",((float)select(arr,0,n-1,n/2) + (float)select(arr,0,n-1,n/2 - 1))/2) : printf("median = %d\n",select(arr,0,n-1,n/2));
  return 0;
}
