#include <iostream>

#include <stdio.h>
#include <stdlib.h>

class Array{
    private:
    int *A;
    int size;
    int length;
    void swap(int *x ,int *y);
    public:
    Array(){
        size=10;
        length=0;
        A=new int[size];
    }
    Array(int sz){
        size=sz;
        length=0;
        A=new int[size];
    }
    ~Array(){
    delete []A;
    }
   void Display();
   void Append(int n);
   void Insert(int index ,int x);
   void Delete(int index);
   int LinearSearch(int key);
   int BinarySearch(int key);
   int Get(int index);
   void Set(int index ,int value);
   int Sum();
   int Avg();
   int Max();
   void Reverse();
   int isSorted();
   void InsertSort(int x);
   void Rearrange();
   Array* Merge(Array arr2);
   Array* Union(Array *arr2);
   Array* Intersection(Array *arr2);
   Array* Difference(Array *arr2);
   void Missing();
   int Duplicate();
   void uDuplicate();
   void pairOfSum(int sum);
};

void Array::Display(){
    for(int i=0; i< length; i++){
        printf("the %d. element is %d \n" ,i+1 ,A[i]);
    }

}

void Array::Append( int n){
    if(length == size){
        printf("There are not any empty spaces! ");
    }else{
        A[length] = n;
        length++;
    }
}

void Array::Insert(int index ,int x){
if( 0<=index && index<= length){
    for(int i= length; i>index; i-- ){
        A[i]=A[i-1];
    }
    A[index]= x;
    length++;
}
}

void Array::Delete(int index){
    if(index >=0 && index < length){
        for(int i = index; i < length; i++){
        A[i] = A[i+1];
        }
        length--;
    }
}
void Array::swap(int *x ,int *y){
    int temp;  
    temp = *x;
    *x=*y;
    *y=temp;
}

int Array::LinearSearch( int key){
    for(int i=0; i<length;i++){
        if(key == A[i]) return i;
    }
    return -1;
}

 int Array::BinarySearch(int key){
    int h = length-1;
    int l = 0;
    int m;

while(l<=h){
     m=(h+l)/2;
    if(key == A[m]){
        return m;
    }
    else if(key < A[m]){
        h = m-1;
    }
    else if(key > A[m]){
        l = m+1 ;
    }
    
}

return -1;
 }



int Array::Get(int index){
    if(index>=0 && index<length) { //check if index is valid
     return A[index];
    }

return -1;
}

void Array::Set(int index ,int value){
    if( index>=0 && index<length){ // check if index is valid
       A[index] = value ;     //set the element to the new value
    }
     
}
int Array::Sum(){
    int sum=0;
    for(int i=0; i<length; i++){
        sum+=A[i];
    }
return sum;
}

int Array::Avg(){
    int sum=0;
    for(int i=0; i<length; i++){
     sum+=A[i];
    }
    return sum/length;
}
int Array::Max(){
int max=0;
for(int i=0; i<length; i++){
 if(A[i]>max){
    max = A[i];
 }   
}
return max;
}

void Array::Reverse(){
int temp;
int i,j;
for(i=0 ,j=length-1; i<=j;i++ ,j--){
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
}

int Array::isSorted(){
    for(int i=0;i<length;i++){
        if(A[i]>A[i-1]){
            return 0;
            }
    }
    return 1;
}


void Array::InsertSort(int x){
    int i = length-1;
    if(length==size)
    return;
    while(i>=0 && x <=A[i]){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}

void Array::Rearrange(){
    int i ,j;
    i=0;
    j=length-1;
    while(i<j){
        while(A[i]<0)i++;
        while(A[j]>=0)j++;
        if(i<j) swap(&A[i] ,&A[j]);
    }
}

Array  * Array::Merge(Array arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=new Array(length+arr2.length);
  arr3->size=size+arr2.size;
   arr3->length=length+arr2.length;
   A=(int *)malloc(size*sizeof(int));

   while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j] ){
      arr3->A[k]=A[i];
      k++ ,i++;
    }
    else{
        arr3->A[k]=arr2.A[j];
        k++ ,j++;
    }
   }
   for(;i<length;i++){
    arr3->A[k]=A[i] ;
    k++;
   }
   for(;j<length;j++){
    arr3->A[k]=arr2.A[j];
    k++;
   }
    return arr3;
}

Array  * Array::Union(Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=size+arr2->size;
   
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

while(i<length && j<arr2->length){
    if(A[i]<arr2->A[j] ){
      arr3->A[k]=A[i];
      k++ ,i++;
    }
    else if(A[i]>arr2->A[j]){
        arr3->A[k]=arr2->A[j];
        k++ ,j++;
    }
    else { 
    arr3->A[k]=A[i];
    k++ ,i++ ,j++;
    }
   }
   for(;i<length;i++){
    arr3->A[k]=A[i];
    k++;
   }
   for(;j<arr2->length;j++){
    arr3->A[k]=arr2->A[j];
    k++;
   }
   arr3->length=k;
    return arr3;
}

Array * Array::Intersection(Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=size+arr2->size;
   
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

   while(i<length && j<arr2->length){
    if(A[i]<arr2->A[j] ){
       i++;
    }
    else if(A[i]>arr2->A[j]){
       j++;
    }
    else { 
    arr3->A[k]=A[i];
     k++ ,i++ ,j++;
    }
   }
  
   arr3->length=k;
    return arr3;
}

Array * Array::Difference(Array *arr2){
   int i ,j ,k;
   i=j=k=0;
   Array *arr3=(Array *)malloc(sizeof(Array));
   arr3->size=arr2->size+size;
   
   arr3->A=(int *)malloc(arr3->size*sizeof(int));

   while(i<length && j<arr2->length){
    if(A[i]<arr2->A[j] ){
      arr3->A[k]=A[i];
      k++ ,i++;
    }
    else if(A[i]>arr2->A[j]){
        arr3->A[k]=arr2->A[j];
        k++ ,j++;
    }
    else { 
     i++ ,j++;
    }
   }
   for(;i<length;i++){
    arr3->A[k]=A[i];
    k++;
   }
   for(;j<arr2->length;j++){
    arr3->A[k]=arr2->A[j];
    k++;
   }
   arr3->length=k;
    return arr3;
}

void  Array::Missing(){
    int dif=A[0]-0;
    for(int i=0; i<length;i++){
        while(A[i]-i != dif){
           printf("%d\n",dif+i);
           dif++; 
        }
    
    }
                                                                                
                                                                                                              
   }

int Array::Duplicate(){
int lastDuplicate=0;
for(int i=0;i<length;i++){
    if(A[i]==A[i+1] && A[i]!=lastDuplicate) {
        printf("%d\n" ,A[i]);
        lastDuplicate=A[i];                 
    }                            
}
return lastDuplicate;
}

void Array::uDuplicate(){
int i ,j;
int count;
for(i=0;i<length-1;i++){
   count=1;
   if(A[i] != -1){

   for(j=i+1;j<length;j++){
     if(A[i]==A[j]){
        count++;  
        A[j]=-1;
     }
    printf("%d appears %d. times \n",A[i] ,j);
   }
   }
}
}

void Array:: pairOfSum(int sum){
int i ,j;
for(i=0;i<length-1;i++){
    if(A[i]!=-1){

    for(j=i+1;j<length;j++){
        if(A[i]+A[j]== sum){
         printf("%d + %d = %d " ,A[i] ,A[j] ,sum );
         A[j]=-1;
        }
    }
    }
}

}

int main(){
Array *arr1;
int ch ,sz;
int index ,x;
printf("Enter the size of Array\n");
scanf("%d",&sz);
arr1=new Array(sz);
 
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
    arr1->Insert(index ,x);
    break;
case 2:
printf("enter an index ");
scanf("%d",&index);
arr1->Delete(index);
break;
case 3:
printf("enter the key element\n ");
scanf("%d",&x);
arr1->BinarySearch(x);
break;
case 4:
printf("The sum is %d\n" ,arr1->Sum());
break;
case 5: arr1->Display();
break;

}
} while(ch<6);
arr1->Duplicate();
    return 0;
}