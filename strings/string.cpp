#include <stdio.h>
#include <stdlib.h>

void Perm(char *arr ,int k){
  static char Res[10];
   static int a[10];
   int i;
   if(arr[k]== '\0'){
    Res[k]='\0';
    printf("%s\n" ,Res);
   }
   for(i=0;arr[i]!='\0';i++ ){
     if(a[i]==0){
        a[i]=1;
        Res[k]=arr[i];
        Perm(arr ,k+1);
        a[i]=0;
     }
   }
}

int main(){
    char name[]="ABC";
    Perm(name ,0);
        return 0;
}