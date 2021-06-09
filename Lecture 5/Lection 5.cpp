#include <iostream>

using namespace std;

// -------------------------------------------------Task1-----------------------------------------------------------
//
//  Написать функцию которая выводит массив double чисел
//  на экран. Параметры функции это сам массив и его размер.
//  Вызвать эту функцию из main.
//

bool print(double arr[], double size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return true;
}

// -------------------------------------------------Task2-----------------------------------------------------------
//
// Задать целочисленный массив, состоящий из элементов 0
// и 1. Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .Написать функцию,
// заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить
// на экран массив до изменений и после. 
//
const int SIZE_ARRAY = 10;
void OneZeroOut(int* OneZero, int size);
void Task2()
{
	int OneZero[SIZE_ARRAY] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
	cout << " This is the first array: " << endl;
	for (int output = 0; output < 10; output++)
	{
		cout << OneZero[output] << endl;
	}
	OneZeroOut(OneZero, SIZE_ARRAY);
}

void OneZeroOut(int* OneZero, int size)
{
	cout << " Result: " << endl;
	for (int output = 0; output < size; output++)
	{
		OneZero[output] = !OneZero[output];
		cout << OneZero[output] << endl;
	}

}

// -------------------------------------------------Task3-----------------------------------------------------------
// 
// Задать пустой целочисленный массив размером 8.
// Написать функцию, которая с помощью цикла заполнит его
// значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.
//


void Task3()
{
	int myarray[23];
	cout << "Result: " << endl;
	for (int i = 1; i < 23; i += 3)
	{
		myarray[i] = i;
		cout << myarray[i] << endl;
	}

}

// -------------------------------------------------Task4-----------------------------------------------------------
//
// Написать функцию, которой на вход подаётся
// одномерный массив и число n(может быть положительным,
// или отрицательным), при этом метод должен циклически
// сместить все элементы массива на n позиций.
//

// С отрицательными числами не знаю как сделать :(
const int size_array = 5;
void Task4()
{
	int temp1[size_array] { 1, 2, 3, 4, 5};
	int temp2[size_array]; 
	int a = 0;
	int write;
	cout << "Please enter number to shift: ";
	cin >> write;
	if (write > size_array)
	{
		cout << "ERROR, please enter the shift element." << endl;
		return Task4_v2();
	}
	if (write >= 0)
	{

		for (int i = 0; i < size_array; i++)
		{
			if (write >= size_array)
			{
				write = 0;
			}
			temp2[a++] = temp1[write++];
		}
	}
	else if (write < 0)
	{
		for (int i = 0; i < size_array; i++)
		{
			if (((size_array - i) + write) < 0)
			{
				write = ;
			}
			temp2[a++] = temp1[(size_array - i) + write];
		}
	}

	for (int i = 0; i < size_array; i++)
	{
		cout << temp1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size_array; i++)
	{
		cout << temp2[i] << " ";
	}
}

// -------------------------------------------------Task5-----------------------------------------------------------
//
// Написать функцию, которой передается не пустой
// одномерный целочисленный массив, она должна вернуть
// истину если в массиве есть место, в котором сумма левой и
// правой части массива равны.
// Примеры: 
// checkBalance([1, 1, 1, || 2, 1]) → true, 
// checkBalance([2, 1, 1, 2, 1]) → false, 
// checkBalance([10, || 1, 2, 3, 4]) → true.
// Абстрактная граница показана символами || , эти символы в массив не входят.
//
// Тут тоже не ососбо понял, вроде сравнивает :)

const int size_5_array = 2;
void Task5_v1()
{
	int left_array[size_5_array];
	int right_array[size_5_array];
	cout << "Enter the array values" << endl;
	for (int i = 0; i < size_5_array; i++)
	{
		cin >> left_array[i];
		cin >> right_array[i];
		if (left_array[i] > right_array[i] || left_array[i] < right_array[i])
		{
			cout << "false" << endl;
			break;
		}
		if (left_array[i] == right_array[i])
		{
			cout << "true" << endl;
			break;
		}
	}

}

/*
bool Task5_v2(int array[])
{
	int length = *array;
	int leftSum;
	int rightSum;


	for (int i = 0; i < length - 1; i++)
	{
		leftSum = 0;
		rightSum = 0;

		for (int j = 0; j <= i; j++)
		{
			leftSum += array[j];
		}

		for (int k = i + 1; k < length; k++)
		{
			rightSum += array[k];
		}

		if (leftSum == rightSum) return true;
	}
	return false;
}
*/

int main()
{
	Task2();
	Task3();
	Task4();
	Task5_v1();
	const double mysize = 5;
	double myarr[] = { 3.14, 265.159, 35.89, 79.32, 38.46 };
	if (print(myarr, mysize))
	{
		cout << "Array was successfuly printed" << endl;
	}
	return 0;
}