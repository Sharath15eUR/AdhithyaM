#include <stdio.h>
int subset(int arr_a[], int arr_b[], int m, int n){
	int i=0;
	int j=0;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			if (arr_b[i] == arr_a[j])
				break;
		}
		if (j == m)
			return 0;
	}
	return 1;
}

int main()
{
	int arr_a[] = {11, 1, 13, 21, 3, 7};
	int arr_b[] = {11, 3, 7, 1};

	int m = sizeof(arr_a) / sizeof(arr_a[0]);
	int n = sizeof(arr_b) / sizeof(arr_b[0]);

	if (subset(arr_a, arr_b, m, n))
		printf("\narray 2 is a subset of array 1");
	else
		printf("\narray 2 is not a subset of array 1");

	int arr_c[] = { 10, 5, 2, 23, 19 };
	int arr_d[] = { 19, 5, 3};

	int x = sizeof(arr_c) / sizeof(arr_c[0]);
	int y = sizeof(arr_d) / sizeof(arr_d[0]);

	if (subset(arr_c,arr_d,x,y))
		printf("\narray 2 is a subset of array 1");
	else
		printf("\narray 2 is not a subset of array 1");

}
