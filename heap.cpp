#include<math.h>
#include<stdio.h>


void enterChoice(int* choice)
{
	printf("Choose Task:\n");
	printf("1 - Enter element\n");
	printf("2 - Display heap\n");
	printf("3 - Max Heapify\n");
	printf("4 - Convert to Max Heap\n");
	printf("5 - Heap Sort\n");
	printf("6 - End\n");
	scanf("%d", choice);
}

// function to correct for single error in maxHeaps
void maxHeapify(int* ar, int i, int len)
{	
	// if we are at the last location then nothing to do
	if(i >= len-1)
		return;

	// else check if maxHeap condition is satisfied
	int max = ar[i], maxLoc = i;
	if(max<ar[2*i+1] && 2*i+1<len-1)
	{
		maxLoc = 2*i+1;
		max = ar[maxLoc];
	}
	if(max<ar[2*i+2] && 2*i+2<len-1)
	{
		maxLoc = 2*i+2;
		max = ar[maxLoc];
	}
	if(maxLoc == i)
		return;

	// else swap and maxheapify child
	ar[maxLoc] = ar[i];
	ar[i] = max;
	maxHeapify(ar, maxLoc, len);
}

void dispHeap(int* ar, int len, int levels)
{
	printf("HEAP:\n");
	int k = 0;
	for(int i = 0; i<levels; i++)
	{
		for(int j = 0; j<pow(2,i) && k < len; j++,k++)
		{
			printf("%d ", ar[k]);
		}
		printf("\n");
	}
	printf("\n");
}

void convMaxHeap(int* ar, int len)
{
	for(int i = (len-1)/2; i>=0; i--)
		{
			maxHeapify(ar, i, len);
		}
}

int main()
{
	// int ar[100] = {10, 2, 9, 9, 7, 5, 6, 6, 3, 2, 1, -1};
	int ar[100] = {1,3,4,8,7,6,9,4,2,1,9,-1};
	int len, levels, choice, element;
	for(len = 0; ar[len]!= -1; len++);
	levels = ceil(log2(len+1));
	bool end = 0;

	while(!end)
	{
		enterChoice(&choice);

		int i, j, k, temp, tempLen;
		switch(choice)
		{
			case 1:
			printf("Enter the element to insert\n");
			scanf("%d", &element);
			ar[len] = element;
			levels = ceil(log2(++len));
			break;

			case 2:
			dispHeap(ar, len, levels);
			
			break;

			case 3:
			printf("Enter location where you'd like to Max Heapify\n");
			scanf("%d", &i);
			maxHeapify(ar, i, len);
			break;

			case 4:
			convMaxHeap(ar, len);
			printf("Converted to Max Heap\n");
			break;

			case 5:
			tempLen = len;
			convMaxHeap(ar, len);
			for(i = 0; i<len; i++)
			{
				temp = ar[tempLen-1];
				ar[tempLen-1] = ar[0];
				ar[0] = temp;
				printf("%d ", ar[tempLen-1]);
				tempLen-=1;
				maxHeapify(ar, 0, tempLen);
			}
			printf("\n");
			break;

			case 6:
			end = 1;
			break;

			default:
			printf("Wrong Choice\n");
			end = 1;
		}

	}
	printf("Exiting\n");
}