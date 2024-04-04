#include<iostream>
using namespace std;
#define tab "\t";

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[],int& n, int value);
void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	Print(arr, n);

	int event_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)event_count++;
		else odd_count++;
	}
	cout << "Колличество четных элементов " << event_count << endl;
	cout << "Колличество нечетных элементов " << odd_count << endl;

	int* even_arr = new int[event_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0) even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];*/
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}
	cout << "Even arr: "; Print(even_arr, event_count);
	cout << "Odd arr: "; Print(odd_arr, odd_count);
	
	delete[] odd_arr;
	delete[] even_arr;

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
		delete[]  arr;
		arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}