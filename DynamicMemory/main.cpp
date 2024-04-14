#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const  int rows, const int cols,int MinRand=0, int MaxRand=100);

template<typename T>void Print(const T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

 void push_col_back(int** arr, const int rows, int& cols);
 void pop_col_back( int** arr, const int rows, int& cols);
 void pop_col_front(int** arr, const int rows, int& cols);

template<typename T>T* push_back(T arr[], int& n, const T value);
int* push_front(int arr[], int& n, const int value);
int* pop_front(int arr[], int& n);

int** insert_row(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols);
void insert_col(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols);

int** push_row_back(int** arr, int& rows, const int cols);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);

template<typename T>T* pop_back(T arr[], int& n);

int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int* insert(int arr[], int& n, const int value);
int* erase(int arr[], int& n);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n = 5;
	cout << "Введите количество элементов: "; cin >> n;

	//1) Объявление динамического массива:
	
	int* arr = new int[n];
	int* buffer = arr;

	//2) Обращение к элементам динамического массива:

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	arr = erase(arr, n);
	Print(arr, n);

	//3) Удаление динамического массива:
	delete[] arr;
	//Memory Leak
#endif

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "Введите колличество строк:  "; cin >> rows;
	cout << "Введите колличество столбцов: "; cin >> cols;
	
	int** arr = Allocate(rows, cols);					//Обьявляем динамический двумерный массив	
	
	FillRand (arr, rows, cols);							//Заполняем его рандомными числами
	Print(arr, rows, cols);
	
	cout << "Добавляем строку в конец массива" << endl;
	arr = push_row_back(arr, rows, cols);				//Добавляем строку в конец массива
	Print(arr, rows, cols);
	cout << "Добавляем строку в начало массива" << endl;
	arr = push_row_front(arr, rows, cols);				//Добавляем строку в начало массива
	Print(arr, rows, cols);
	
	cout << "Добавляем столбец в конец массива" << endl;
	push_col_back(arr, rows, cols);						//Добавляем столбец в конец массива
	Print(arr, rows, cols);
	cout << "Добавляем столбец в начало массива" << endl;
	push_col_front(arr, rows, cols);					//"Добавляем столбец в начало массива
	Print(arr, rows, cols);

	cout << "Удаляем строку в конце массива" << endl;
	arr = pop_row_back(arr,rows,cols);					//Удаляем строку в конце массива
	Print(arr, rows, cols);
	cout << "Удаляем строку в началe массива" << endl;	
	arr = pop_row_front(arr, rows, cols);					//Удаляем строку в начале массива
	Print(arr, rows, cols);

	cout << "Удаляем Столбец в конце массива" << endl;	
	pop_col_back(arr, rows, cols);						//Удаляем Столбец в конце массива
	Print(arr, rows, cols);
	cout << "Удаляем Столбец в началe массива" << endl;
	pop_col_front(arr, rows, cols);						//Удаляем Столбецв начале массива
	Print(arr, rows, cols);

	cout << "Вставляем строку по индексу" << endl;
	arr = insert_row(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Вставляем Столбец по индексу" << endl;
	insert_col(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем строку по индексу" << endl;
	arr = erase_row(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Удаляем Столбец по индексу" << endl;
	erase_col(arr, rows, cols);
	Print(arr, rows, cols);

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
template<typename T>void Print(const T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

template<typename T> T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
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
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* insert(int arr[], int& n, const int value)
{
	int num;
	cout << "Введите индекс элемента: "; cin >> num;
	int* buffer = new int[n + 1];
	for (int i = 0; i < num; i++) buffer[i] = arr[i];
	buffer[num] = value;
	for (int i = num; i < n; i++) buffer[i+1] = arr[i];

	delete[] arr;
	n++;
	
	return buffer;
}
template<typename T>T* pop_back(T arr[], int& n)
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
	cout << "Введите индекс элемента: "; cin >> num;
	int* buffer = new int[--n];
	for (int i = 0; i < num; i++) buffer[i] = arr[i];
	for (int i = num; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}

template<typename T>void Print(T** arr, const int rows, const int cols)
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
void FillRand(int** arr, const  int rows, const int cols, int MinRand, int MaxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (MaxRand - MinRand) + MinRand;
		}
	}
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < cols; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols]{};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < cols; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols)
{
	int num;
	cout << "Введите индекс элемента: "; cin >> num;
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < num; i++)buffer[i] = arr[i];
	buffer[num] = new int [cols] {};
	for (int i = num; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols)
{
	int num;
	cout << "Введите индекс элемента: "; cin >> num;
	int** buffer = new int* [--rows];
	for (int i = 0; i < num; i++)buffer[i] = arr[i];
	for (int i = num; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** pop_row_back(int** arr,int& rows, const int cols)
{
	int** buffer = new int* [--rows];						//Удаляем из памяти строку двумерного массива
	delete[] arr[rows]; 
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	
	int** buffer = new int* [--rows];
	delete[] arr[0];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}

void push_col_back( int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols)
{
	int num;
	cout << "Введите индекс элемента: "; cin >> num;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < num; j++)buffer[j] = arr[i][j];
		for (int j = num; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void erase_col(int** arr, const int rows, int& cols)
{
	int num;
	cout << "Введите индекс элемента: "; cin >> num;
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols] {};
		for (int j = 0; j < num; j++)buffer[j] = arr[i][j];
		for (int j = num; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
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
void pop_col_front(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
