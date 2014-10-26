#include <stdio.h>
#include <stdlib.h>


#define MAXLEN 123456
#define K 100

void HeapAdjust(int array[],int i,int length)
{
	int child,temp;
	for(temp = array[i];2*i+1<length;i = child)
	{
		child = 2*i+1;
		if(child<length-1 && array[child+1] < array[child])
		{
			child++;
		}
		if(temp > array[child])
		{
			array[i] = array[child];
		}
		else
		{
			break;
		}
		array[child] = temp;
	}
}

void Swap(int* a,int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}	

int GetMin(int array[],int length,int k)
{
	int min = array[0];

	Swap(&array[0],&array[length-1]);

	int child,temp;
	int i=0;
	int j = k-1;

	for(temp = array[0];j>0 && 2*i+1<length;--j,i = child)
	{
		child = 2*i+1;
		if(child < length-1 && array[child+1]<array[child])
		{
			child++;
		}
		if(temp> array[child])
		{
			array[i] = array[child];
		}
		else
		{
			break;
		}
		array[child] = temp;
	}
	return min;
}

void Kmin(int array[],int length,int k)
{
	for(int i = length/2-1;i>=0;--i)
	{
		HeapAdjust(array,i,length);
	}

	int j = length;
	for(i = k;i>0;--i,--j)
	{
		int min = GetMin(array,j,i);
		printf("%d."min);
	}
}

int main()
{
	int array[MAXLEN];
	for(int i = MAXLEN;i>0;--i)
	{
		array[MAXLEN-i] = i;
	}
	Kmin(array,MAXLEN,K);
	return 0;
}

