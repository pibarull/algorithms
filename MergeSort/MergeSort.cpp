

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

int begin, end;
const int n = 9;

void Merge(int *A, int begin, int mid, int end);

void printArr(int *A, int begin, int end)
{
	for (int i = begin; i <= end; i++)
		printf("%i ", A[i]);
}

void  MergeSort(int *A, int begin, int end)
{
	if (begin < end)
	{
		int mid = ((end + begin) / 2);

		MergeSort(A, begin, mid); 
		MergeSort(A, mid+1, end);
		
		Merge(A, begin, mid, end);
	}
}

void Merge(int *A, int begin, int mid, int end)
{
	int *Arr = (int*)malloc((end - begin + 1) * sizeof(int));
	int lArr = 0;
	int l = begin, p = mid + 1;

	for (int i = begin; i <= end; i++) {
		if (l > mid)      //ëåâàÿ ÷àñòü äîøëà ëè äî êîíöà
		{
			Arr[lArr++] = A[p++];
			//printf("%i ", Arr[lArr-1]);
		}
		else if (p > end)   //ïðàâàÿ ÷àñòü äîøëà ëè äî êîíöà
		{
			Arr[lArr++] = A[l++];
			//printf("%i ", Arr[lArr-1]);
		}
		else if (A[l] < A[p])     //ñðàâíèâàåì ýëåìåíòû ïðàâîé è ëåâîé ÷àñòè
		{
			Arr[lArr++] = A[l++];
			//printf("%i ", Arr[lArr-1]);
		}
		else
		{
			Arr[lArr++] = A[p++];
			//printf("%i ", Arr[lArr-1]);
		}
	}
	for (int i = 0; i< lArr; i++) //ôîðìèðóåì îòñîðòèðîâàííûé ìàññèâ
		A[begin++] = Arr[i];
	//printf("\n");
		free(Arr);
}



void main()
{
	int *A = (int*)malloc(n * sizeof(int));
	int sA[n] = {4,1,8,66,2,35,3,5,7};
	//int sA[n] = { 3, 2, 4, 1 , 5 };
	for (int i = 0; i < n; i++)
		A[i] = sA[i];
	
	MergeSort(A, 0, n-1);
	printArr(A, 0, n-1);
	/*
	for (int i = 0; i < n - 1; i++)
		if (A[i] > A[i+1])
		{
			printf("error\n"); break;
		}*/
	
	free(A);
}

