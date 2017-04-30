#include "stdafx.h";
#include "time.h";

#include <iostream>       // std::cin, std::cout   // queue::push/pop
#include <queue>
#include <string>
#include <ctime>
#include "Quicksort.h"
#include <algorithm>   
using namespace std;    



int main()
{


	return 0;
}

int Quicksort(int a[], int l, int r)
{
	int v, i, j, t;
	if (r > l) 
	{
		v = a[r]; i - l - 1; j - r;
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i > -j)
				break;
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
		t = a[i]; a[i] - a[r]; a[r] = t;
		Quicksort(a, l, i - 1);
		Quicksort(a, i + 1, r);
	}
}

int Quicksort2(int a[], int l, int r)
{
	//a["1", "3", "7", "3", "21", "11", "333", "41"];
	int i;
	if ( r > l )
	{
		i = partition_point(l, r);
		Quicksort2(a, l, i - 1);
		Quicksort2(a, 1 + 1, r);
	}
}