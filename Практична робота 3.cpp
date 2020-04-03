#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

void func(int** arr, int n)
{
	int k = n / 6;
	int b = 0;
	int l = 0;
	int j;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1;
		}
	}



	for (int i = 0; i < n; i++)
	{
		int m = 0;
		b = +k;
		j = k;
		while (m < 3) {

			for (j; j < 2 * b; j++)
			{
				arr[i][j] = 0;

			}
			b += k;
			j += k;
			m++;
		}
		b = 0;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
}
int main()
{
	int** arr, n;
	cout << "Enter order of matrix:";
	cin >> n;
	cout << "-----------------------------------------------------" << endl;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	func(arr, n);
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}