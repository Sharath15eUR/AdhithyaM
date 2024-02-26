#include <stdio.h>
#include <stdlib.h>

void swap(int*x,int*y){
int temp;
temp = *x;
*x=*y;
*y=temp;
}

int main(){

void(*swap_func)(int*,int*);

int a,b;
printf("enter number in var. a = ");
scanf("%d",&a);
printf("enter number in var. b = ");
scanf("%d",&b);

printf("\tbefore swap \n\t a=%d \n\t b=%d\n",a,b);
swap_func=swap;
(*swap_func)(&a,&b);

printf("\tafter swap \n\t a=%d \n\t b=%d\n",a,b);


}

