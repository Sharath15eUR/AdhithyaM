#include <stdio.h>
#include <stdlib.h>

int main(){

	int num,a,count=0;
    printf("\nEnter the number: ");
	scanf("%d",&num);
	while(num!=0){
		a = num&1;
		if(a==1)
			count+=1;
		num>>=1;
	}
	printf("\nThe count of bit sets in the entered number is: %d", count);
	return 0;
}


