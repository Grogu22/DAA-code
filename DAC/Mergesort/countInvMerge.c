#include <stdio.h>
int merge(int arr[],int l,int mid, int r){
  int inv = 0;
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int a[n1];
  int b[n2];
  for(int i=0; i <n1; i++) a[i] = arr[l+i] ;
  for(int i=0; i <n2; i++) b[i] = arr[mid+i+1];
  int i=0, j =0, k=l;
  while (i < n1 && j < n2) {
    if(a[i] <= b[j]){
      arr[k] = a[i];
      i++, k++;
    }else{
      arr[k] = b[j];
      inv+= n1 - i;
      j++ ,k++;
    }
  }while (i < n1) {
    arr[k] = a[i];
    k++, i++;
  }while (j < n2) {
    arr[k] = b[j];
    k++, j++;
  }
  return inv;
}
int mergeSort(int arr[],int l,int r){
  int inv = 0;
  if (l < r){
    int mid = (l + r)/2;
    inv += mergeSort(arr,l,mid);
    inv += mergeSort(arr,mid+1,r);
    inv += merge(arr,l,mid,r);
  }
  return inv;
}
int main() {
  int n;
  printf("Enter number of elements : ");
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i <n;i++){
    printf("\nEnter %dst element : ",i+1);
    scanf("%d",&arr[i]);
  }
  printf("Number of inversions are : %d\n",mergeSort(arr,0,n-1));
  return 0;
}
