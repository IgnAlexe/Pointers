#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);

//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n = 5;
	cout << "¬ведите количество элементов: "; cin >> n;

	//1) ќбъ€вление динамического массива:
	int* arr = new int[n];
	int* buffer = arr;

	//2) ќбращение к элементам динамического массива:

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "¬ведите добавл€емое значение: "; cin >> value;

	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	//3) ”даление динамического массива:
	delete[] arr;
	//Memory Leak
#endif

#ifdef DINAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "¬ведите колличество строк:  "; cin >> rows;
	cout << "¬ведите колличество столбцов: "; cin >> cols;
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	Print(arr, rows, cols); 
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[]arr;
	
#endif

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
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;*/
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer; 


}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}