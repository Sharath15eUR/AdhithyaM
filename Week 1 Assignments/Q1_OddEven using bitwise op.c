#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number & 1)
	{
        printf("%d is an odd number.\n\n", number);
    }
	else
	{
        printf("%d is an even number.\n\n", number);
    }

}

