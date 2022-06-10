#include <stdio.h>
#include <stdlib.h>
int cmpfnc(const void* a, const void* b){
 return (*(int*)a - *(int*)b);
}
int binarySearch(int arr[], int l, int r, int x)
{
  if(l <= r)
  {
    int mid = l + (r-l)/2;
    if (arr[mid] == x) 
        return mid;  
    else if (arr[mid] < x) 
        return binarySearch(arr,mid+1,r,x); 
    return binarySearch(arr,l,mid-1,x); 
  }
  return -1; 
}

int main(){
int n,x,i;
 printf("Enter no of elements in array :");
 scanf("%d",&n);
 int arr[n];
 for(i =0;i < n;i++){
 printf("Enter %d the element of array:",i+1);
 scanf("%d",&arr[i]);
 }
 qsort(arr,n,sizeof(int),cmpfnc);
 printf("Enter element to search:");
 scanf("%d",&x);
 printf("Sorted array:");
for(i =0;i < n;i++){
 printf("%d ",arr[i]);
 }
printf("\n");
 int a = binarySearch(arr,0,n-1,x);
 if (a == -1){
  printf("Element not in array");
 }
else{
 printf("Element in index %d",a);
 }
 return 0;
}
