#include <stdio.h>
#include <stdlib.h>
int reverse(int *arr, int n){
int temp=0 ;
for(int i=0; i<n/2; i++){
temp = arr[i];
arr[i] = arr[n-i-1];
arr[n-i-1] = temp;
}
return 0;
}

int main(){
int n ;
int *arr;
printf("Please enter the size of your array: \n");
scanf("%d",&n);
arr = (int *)malloc(n*sizeof(int));
printf("Please enter the elements of your array:\n");
for(int i=0; i<n; i++){
    scanf("%d" ,&arr[i]);
}
printf("Original Array: \n");
for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
}
reverse(arr, n);
printf("Reversed Array: \n");
for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
}
free(arr);
return 0;
}