#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int low, int mid, int high) //time comp. O(n) ; space comp. O(n)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int left[n1];
	int right[n2];

	while (i < n1)
	{
		a[k] = left[i];
		k++;
		i++;
	}

	while (j < n2)
	{
		a[k] = right[j];
		k++;
		j++;
	}
}

int main()
{
	int a[] = {1, 3, 5, 7, 2, 4, 6};
	int n = sizeof(a) / sizeof(int);

	int low = 0;
	int high = (n - 1);
	int mid = (low + high) / 2;

	merge(a, low, mid, high);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
