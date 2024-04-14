#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const  int rows, const int cols,int MinRand=0, int MaxRand=100);
void FillRand(double** arr, const  int rows, const int cols, int MinRand = 0, int MaxRand = 100);

template<typename T>void Print(const T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_back( T** arr, const int rows, int& cols);
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);

template<typename T>T* push_back(T arr[], int& n, const T value);
template<typename T>T* push_front(T arr[], int& n, const T value);
template<typename T>T* pop_front(T arr[], int& n);

template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index);
template<typename T>T** erase_row(T** arr, int& rows, const int cols,int index);
template<typename T>void insert_col(T** arr, const int rows, int& cols,int index);
template<typename T>void erase_col(T** arr, const int rows, int& cols,int index);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);

template<typename T>T* pop_back(T arr[], int& n);

template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);

template<typename T>T* insert(T arr[], int& n, const T value);
template<typename T>T* erase(T arr[], int& n);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n = 5;
	cout << "������� ���������� ���������: "; cin >> n;

	//1) ���������� ������������� �������:
	
	int* arr = new int[n];
	int* buffer = arr;

	//2) ��������� � ��������� ������������� �������:

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = insert(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	arr = erase(arr, n);
	Print(arr, n);

	//3) �������� ������������� �������:
	delete[] arr;
	//Memory Leak
#endif

#ifdef DYNAMIC_MEMORY_2

	int rows;
	int cols;
	cout << "������� ����������� �����:  "; cin >> rows;
	cout << "������� ����������� ��������: "; cin >> cols;
	
	double** arr = Allocate<double>(rows, cols);					//��������� ������������ ��������� ������	
	
	FillRand (arr, rows, cols);							//��������� ��� ���������� �������
	Print(arr, rows, cols);
	
	cout << "��������� ������ � ����� �������" << endl;
	arr = push_row_back(arr, rows, cols);				//��������� ������ � ����� �������
	Print(arr, rows, cols);
	cout << "��������� ������ � ������ �������" << endl;
	arr = push_row_front(arr, rows, cols);				//��������� ������ � ������ �������
	Print(arr, rows, cols);
	
	cout << "��������� ������� � ����� �������" << endl;
	push_col_back(arr, rows, cols);						//��������� ������� � ����� �������
	Print(arr, rows, cols);
	cout << "��������� ������� � ������ �������" << endl;
	push_col_front(arr, rows, cols);					//"��������� ������� � ������ �������
	Print(arr, rows, cols);

	cout << "������� ������ � ����� �������" << endl;
	arr = pop_row_back(arr,rows,cols);					//������� ������ � ����� �������
	Print(arr, rows, cols);
	cout << "������� ������ � �����e �������" << endl;	
	arr = pop_row_front(arr, rows, cols);					//������� ������ � ������ �������
	Print(arr, rows, cols);

	cout << "������� ������� � ����� �������" << endl;	
	pop_col_back(arr, rows, cols);						//������� ������� � ����� �������
	Print(arr, rows, cols);
	cout << "������� ������� � �����e �������" << endl;
	pop_col_front(arr, rows, cols);						//������� �������� ������ �������
	Print(arr, rows, cols);

	cout << "��������� ������ �� �������" << endl;
	int index;
	cout << "������� ������ ��������: "; cin >> index;
	arr = insert_row(arr, rows, cols,index);
	Print(arr, rows, cols);
	cout << "��������� ������� �� �������" << endl;
	cout << "������� ������ ��������: "; cin >> index;
	insert_col(arr, rows, cols,index);
	Print(arr, rows, cols);

	cout << "������� ������ �� �������" << endl;
	cout << "������� ������ ��������: "; cin >> index;
	arr = erase_row(arr, rows, cols,index);
	Print(arr, rows, cols);
	cout << "������� ������� �� �������" << endl;
	cout << "������� ������ ��������: "; cin >> index;
	erase_col(arr, rows, cols,index);
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
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[]  arr;
	buffer[n++] = value;
	return buffer;
}
template<typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T>T* insert(T arr[], int& n, const T value)
{
	int num;
	cout << "������� ������ ��������: "; cin >> num;
	T* buffer = new T[n + 1];
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
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
template<typename T>T* erase(T arr[], int& n)
{
	int num;
	cout << "������� ������ ��������: "; cin >> num;
	T* buffer = new T[--n];
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
template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
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
void FillRand(double** arr, const  int rows, const int cols, int MinRand, int MaxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (MaxRand - MinRand) + MinRand;
		}
	}
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	/*T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows++] = new T[cols]{};
	return buffer;*/
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	/*T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;*/
	return push_front(arr, rows, new T[cols]{});
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	buffer[index] = new T [cols] {};
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_back(T** arr,int& rows, const int cols)
{
	/*T** buffer = new T * [--rows];						//������� �� ������ ������ ���������� �������
	delete[] arr[rows]; 
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	return buffer;*/
	
	delete[] arr[rows-1];
	return pop_back(arr, rows);
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	
	T** buffer = new T* [--rows];
	delete[] arr[0];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}

template<typename T>void push_col_back( T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, const int rows, int& cols,int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void erase_col(T** arr, const int rows, int& cols,int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
