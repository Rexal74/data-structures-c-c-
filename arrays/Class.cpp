#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *A;
    int size;
    int length;
} Array;

void Display(Array A){
    for(int i=0; i< A.length; i++){
        printf("the %d. element is %d \n" ,i+1 ,A.A[i]);
    }

}

void Append(Array *A, int n){
    if(A->length == A->size){
        printf("There are not any empty spaces! ");
    }else{
        A->A[A->length] = n;
        A->length++;
    }
}

void Insert(Array *A ,int index ,int x){
if( 0<=index && index<= A->length){
    for(int i= A->length; i>index; i-- ){
        A->A[i]=A->A[i-1];
    }
    A->A[index]= x;
    A->length++;
}
}

void Delete(Array *A, int index){
    if(index >=0 && index < A->length){
        for(int i = index; i < A->length; i++){
        A->A[i] = A->A[i+1];
        }
        A->length--;
    }
}
void swap(int *x ,int *y){
    int temp;  
    temp = *x;
    *x=*y;
    *y=temp;
}

int LinearSearch(Array A, int key){
    for(int i=0; i<A.length;i++){
        if(key == A.A[i]) return i;
    }
    return -1;
}

 int BinarySearch( Array a ,int key){
    int h = a.length-1;
    int l = 0;
    int m;

while(l<=h){
     m=(h+l)/2;
    if(key == a.A[m]){
        return m;
    }
    else if(key < a.A[m]){
        h = m-1;
    }
    else if(key > a.A[m]){
        l = m+1 ;
    }
    
}

return -1;
 }

int RBinarySearch(int a[] ,int h ,int l ,int key){
    int m;
    if( l<=h){         
       m=(l+h)/2;
       
       if(key == a[m]){ //key found ,return index
           return m;
       }else if(key < a[m]){ //search the left half
           return RBinarySearch( a ,m-1 ,l ,key);
       }else if(key >a[m]){ //search the right half
           return RBinarySearch(a ,h ,m+1 ,key);
       }
      
    }
    return -1;
}

int Get(Array arr ,int index){
    if(index>=0 && index<arr.length) { //check if index is valid
     return arr.A[index];
    }

return -1;
}

void Set(Array *arr ,int index ,int value){
    if( index>=0 && index<arr->length){ // check if index is valid
       arr->A[index] = value ;     //set the element to the new value
    }
     
}
int Sum(Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++){
        sum+=arr.A[i];
    }
return sum;
}

int Avg(Array arr){
    int sum=0;
    for(int i=0; i<arr.length; i++){
     sum+=arr.A[i];
    }
    return sum/arr.length;
}
int Max(Array arr){
int max=0;
for(int i=0; i<arr.length; i++){
 if(arr.A[i]>max){
    max = arr.A[i];
 }   
}
return max;
}

void Reverse(Array *arr){
int temp;
int i,j;
for(i=0 ,j=arr->length-1; i<=j;i++ ,j--){
    temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
}
}

int isSorted(Array arr){
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>arr.A[i-1]){
            return 0;
            }
    }
    return 1;
}


void InsertSort(Array *arr ,int x){
    int i = arr->length-1;
    if(arr->length==arr->size)
    return;
    while(i>=0 && x <=arr->A[i]){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

void Rearrange(Array *arr){
    int i ,j;
    i=0;
    j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j++;
        if(i<j) swap(&arr->A[i] ,&arr->A[j]);
    }
}

Array  *Merge(Array *arr1 ,Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=arr2->size+arr1->size;
   arr3->length=arr2->length+arr1->length;
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

   while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j] ){
      arr3->A[k]=arr1->A[i];
      k++ ,i++;
    }
    else{
        arr3->A[k]=arr2->A[j];
        k++ ,j++;
    }
   }
   for(;i<arr1->length;i++){
    arr3->A[k]=arr1->A[i];
    k++;
   }
   for(;j<arr2->length;j++){
    arr3->A[k]=arr2->A[j];
    k++;
   }
    return arr3;
}

Array  *Union(Array *arr1 ,Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=arr2->size+arr1->size;
   
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

   while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j] ){
      arr3->A[k]=arr1->A[i];
      k++ ,i++;
    }
    else if(arr1->A[i]>arr2->A[j]){
        arr3->A[k]=arr2->A[j];
        k++ ,j++;
    }
    else { 
    arr3->A[k]=arr1->A[i];
    k++ ,i++ ,j++;
    }
   }
   for(;i<arr1->length;i++){
    arr3->A[k]=arr1->A[i];
    k++;
   }
   for(;j<arr2->length;j++){
    arr3->A[k]=arr2->A[j];
    k++;
   }
   arr3->length=k;
    return arr3;
}

Array  *Intersection(Array *arr1 ,Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=arr2->size+arr1->size;
   
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

   while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j] ){
       i++;
    }
    else if(arr1->A[i]>arr2->A[j]){
       j++;
    }
    else { 
    arr3->A[k]=arr1->A[i];
     k++ ,i++ ,j++;
    }
   }
  
   arr3->length=k;
    return arr3;
}

Array  *Difference(Array *arr1 ,Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=arr2->size+arr1->size;
   
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

   while(i<arr1->length && j<arr2->length){
    if(arr1->A[i]<arr2->A[j] ){
      arr3->A[k]=arr1->A[i];
      k++ ,i++;
    }
    else if(arr1->A[i]>arr2->A[j]){
        arr3->A[k]=arr2->A[j];
        k++ ,j++;
    }
    else { 
     i++ ,j++;
    }
   }
   for(;i<arr1->length;i++){
    arr3->A[k]=arr1->A[i];
    k++;
   }
   for(;j<arr2->length;j++){
    arr3->A[k]=arr2->A[j];
    k++;
   }
   arr3->length=k;
    return arr3;
}


int main(){
Array arr1;
int ch ,index ,x;
printf("Please enter the size of your array\n");
scanf("%d" ,&arr1.size);
printf("Please enter the length of your array\n");
scanf("%d" ,&arr1.length);
arr1.A=(int *) malloc(arr1.size*sizeof(int));
do{

printf("Menu\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Search\n");
printf("4. Sum\n");
printf("5. Display\n");
printf("6. Exit\n");

printf("enter your choice ");
scanf("%d" ,&ch);
switch(ch){
    case 1:
    printf("enter an element and index ");
    scanf("%d%d",&x ,&index);
    Insert(&arr1 ,index ,x);
    break;
case 2:
printf("enter an index ");
scanf("%d",&index);
Delete(&arr1 ,index);
break;
case 3:
printf("enter the key element ");
scanf("%d",&x);
BinarySearch(arr1 ,x);
break;
case 4:
printf("The sum is %d" ,Sum(arr1));
break;
case 5: Display(arr1);
break;

}
} while(ch<6);
    return 0;
}