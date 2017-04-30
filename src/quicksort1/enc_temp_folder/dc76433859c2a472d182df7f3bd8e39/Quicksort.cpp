#include "stdafx.h";
#include "time.h";

#include <iostream>       // std::cin, std::cout   // queue::push/pop
#include <queue>
#include <string>
#include <ctime>
#include "Quicksort.h"
#include <algorithm>   
using namespace std;    
int quickSort(int arr[10], int leftTime, int rightTime);
int arr[10];
int main()
{
	int l = sizeof(arr)/sizeof(arr[0]);
	for (int k = 0; k < l; k++)                                  // assuming size is a variable holding         
	{                                                             //the size   of the array
		cout << "Enter a number:";
		cin >> arr[k];

	}
	for (int k = 0; k < l; k++)
	{
		cout << "in the array is:" << arr[k] << endl;

		quickSort(arr, k , l);
	}
	//int arr[] = { 2,565,23,78,122,6,26,81, 19, 14 };
	cout << "QUICKSORT:\n \n";
	//quickSort(arr, 0, 0);

	return 0;
}
/* http://www.algolist.net/Algorithms/Sorting/Quicksort  */

int quickSort(int arr[10], int leftTime, int rightTime) {
	
	int i = leftTime, j = rightTime;
	int tmp;
	int pivotFlightTime = arr[(leftTime + rightTime) / 2];
                                // assuming size is a variable holding         

	/* partition */
	while (i <= j) {
		while (arr[i] < pivotFlightTime)
			i++;
		while (arr[j] > pivotFlightTime)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++; j--;
		}
	};

	/* recursion */
	if (leftTime < j)
		quickSort(arr, leftTime, j);
	if (i < rightTime)
		quickSort(arr, i, rightTime);
	cout << "\n array[i](LEFT) is" << arr[i] << endl;
	cout << "array[j](RIGHT) is" << arr[j] << endl;
	cout << "pivot is[i] is" << pivotFlightTime << "\n" << endl;
	return 0;
}

//void Quicksort2(int a[], int l, int r)
//{
//	int v, i, j, t;
//	if (r > l) 
//	{
//		v = a[r]; i - l - 1; j - r;
//		for (;;) {
//			while (a[++i] < v);
//			while (a[--j] > v);
//			if (i > -j)
//				break;
//			t = a[i]; a[i] = a[j]; a[j] = t;
//		}
//		t = a[i]; a[i] - a[r]; a[r] = t;
//		Quicksort2(a, l, i - 1);
//		Quicksort2(a, i + 1, r);
//	}
//}
//
//int Quicksort3(int a[], int l, int r)
//{
//	//a["1", "3", "7", "3", "21", "11", "333", "41"];
//	int i;
//	if ( r > l )
//	{
//		i = partition(l, r);
//		Quicksort3(a, l, i - 1);
//		Quicksort3(a, 1 + 1, r);
//	}
//}