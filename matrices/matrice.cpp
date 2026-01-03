#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class Diagonal{
    private:
   int *A;
   int n;
   public:
   Diagonal(int size){
    n=size;
    A=new int[n];
}
  void Set(int i,int j,int x);
  int Get(int i,int j);
  void Display();
};

void Diagonal::Set(int i,int j,int x){
if(i==j){
    A[i-1]=x;
}
}
int Diagonal::Get(int i,int j){
    if(i==j){
        return A[i-1];
    }
    return 0;
}
void Diagonal::Display(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        if(i==j){
        printf("%d",A[i]);
        }else printf("0");
        }
        printf("\n");
    }
}

class LowerTriangular{
    private:
int *A;
int n;
    public:
LowerTriangular(int size){
n=size;
A=new int[size];
}
void Set(int i,int j,int k);
int Get(int i,int j);
void Display();

};

void LowerTriangular::Set(int i,int j,int k){
    if(i>=j){
        A[(i-1)*(i)/2+j-1]=k;
    }
}
int LowerTriangular::Get(int i,int j){
    if(i>=j){
        return   A[(i-1)*(i)/2+j-1];
    }
    return 0;
}

void LowerTriangular::Display(){
int i,j;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(i>=j){
        printf(" %d " ,A[(i-1)*(i)/2+j-1]);
        }else{
        printf(" 0 ");
    }
    
    }
    printf("\n");
} 
}


int main(){
   LowerTriangular m(3);
m.Set(1,1,2),m.Set(2,1,3),m.Set(2,2,3),m.Set(3,1,3),m.Set(3,2,3),m.Set(3,3,2);
m.Display();
   
    return 0;
}