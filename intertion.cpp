#include<ctime>
#include<stdio.h>

void insort(int* ar, int n)
{
	for(int i=1; i<n; i++)
	{
		int j=i-1, key = ar[i];
		for(; j>=0 && ar[j]>key; j--)
		{
			ar[j+1] = ar[j];
		}
		ar[j+1] = key;
	}
}

int main()
{
	printf("hello\n");
	int ar[] = {10,20,3, 19, 34, 2, 1, 4, 100, 202}, n=10;
	time_t current_time = time(NULL);
	insort(ar, n);
	printf("%f\n", double(time(NULL)));
	for(int i=0; i<n; i++)
		printf("%d ", ar[i]);
	return(0);
}