#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
int** push_row_back(int** arr, int& rows, const int cols);
void FillRand(int** arr, const  int rows, const int cols,int MinRand, int MaxRand);


void push_col_back(int** arr, const int rows, int& cols);

void pop_col_back(int** arr, const int rows, int& cols);

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n);

//void Allocate(int** arr, const int rows, const int cols);
//void Clear(int** arr, const int rows, const int cols);

//int** push_row_back(int** arr, int& rows, const int cols);

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

	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = insert(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	arr = erase(arr, n);
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
	Allocate(rows, cols);
	
	Print(arr, rows, cols); 
	FillRand (arr[rows-1], rows, cols,100,1000);
	Print(arr, rows, cols);

	arr=push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = pop_row_back(arr,rows,cols);
	Print(arr, rows, cols);
	pop_col_back

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	//arr = push_row_back(arr, rows, cols);
	//Print(arr, rows, cols);
	
	Clear(arr, rows);
	
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
int* insert(int arr[], int& n, const int value)
{
	int num;
	cout << "¬ведите индекс элемента: "; cin >> num;
	int* buffer = new int[n + 1];
	for (int i = 0; i < num; i++) buffer[i] = arr[i];
	buffer[num] = value;
	for (int i = num; i < n; i++) buffer[i+1] = arr[i];

	delete[] arr;
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
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
int* erase(int arr[], int& n)
{
	int num;
	cout << "¬ведите индекс элемента: "; cin >> num;
	int* buffer = new int[--n];
	for (int i = 0; i < num; i++) buffer[i] = arr[i];
	for (int i = num; i < n; i++) buffer[i] = arr[i+1];
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
	cout << endl;
}
/**void Allocate(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr [i] = new int[cols] {};
	}
}

int** push_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int*[rows + 1];
	
	Allocate(arr , rows, cols);
	Clear(arr , rows, cols);
	rows++;
	return buffer;
}*/
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[]arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < cols; i++)buffer[i] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
}
void FillRand(int** arr,const  int rows, const int cols, int MinRand, int MaxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (MaxRand-MinRand)+MinRand;
		}
	}
	//return arr;
}
int** pop_row_back(int** arr,int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	delete[] arr[rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; i < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}