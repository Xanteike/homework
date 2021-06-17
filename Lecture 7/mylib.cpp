#include "mylib.h"


//
// Создайте проект из 2х cpp файлов и заголовочного (main.cpp,
// mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
// для инициализации массива(типа float), печати его на экран и
// подсчета количества отрицательных и положительных
// элементов.Вызывайте эти 3 - и функции из main для работы с массивом.
//
// Сделайте задание 1 добавив свой неймспейс во втором модуле(первое задание тогда можно не делать)

namespace MyLib
{
    void printArray(float arr[], const int size)
    {
        std::cout << "Congratulations! Your array: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

    }

    void cinArray(float arr[], const int size)
    {
        std::cout << "Enter the data in the float array" << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
        std::cout << std::endl;

    }

    void countingArray(float arr[], const int size)
    {
        int a = 0;
        int b = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0)
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        std::cout << "Positive numbers = " << b << std::endl;
        std::cout << "Negative numbers = " << a << std::endl;
    }
}

//
// Описать макрокоманду (через директиву define),
// проверяющую, входит ли переданное ей число(введенное с
// клавиатуры) в диапазон от нуля(включительно) до переданного
// ей второго аргумента(исключительно) и возвращает true или
//  false, вывести на экран «true» или «false»
//

#define TASK2_DEFINE(a, b) a >= 0 && a < b ? true : false
void Task2()
{
    std::cout << "Enter a: ";
    int write;
    std::cin >> write;

    std::cout << "Enter b: ";
    int write2;
    std::cin >> write2;

    int result = TASK2_DEFINE(write, write2);
    std::cout << "a < b = " << (result ? "true" : "false") << std::endl;
}

//
// Задайте массив типа int. Пусть его размер задается через
// директиву препроцессора #define. Инициализируйте его через
// ввод с клавиатуры. Напишите для него свою функцию
// сортировки(например Пузырьком). Реализуйте перестановку
// элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
//
#define SIZE_ARRAY 5
#define SwapINT(a, b) std::swap(a, b)

void Task3print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Task3Sort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                SwapINT(arr[j], arr[j + 1]);
            }
        }
    }
}

void Task3()
{
    int arr[SIZE_ARRAY];

    std::cout << "Fill in the array" << std::endl;

    for (int i = 0; i < SIZE_ARRAY; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Initial array: ";
    Task3print(arr, SIZE_ARRAY);


    Task3Sort(arr, SIZE_ARRAY);
    std::cout << "Array after sorting: ";
    Task3print(arr, SIZE_ARRAY);
}
//
// Объявить структуру Сотрудник с различными полями.
// Сделайте для нее побайтовое выравнивание с помощью
// директивы pragma pack. Выделите динамически переменную
// этого типа. Инициализируйте ее. Выведите ее на экран и ее
// размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
//
void Task4()
{
    Employee emp;
    emp.id = 1;
    emp.age = 25;
    emp.salary = 178.000;
    std::cout << "ID: " << emp.id << std::endl 
              << "AGE: " << emp.age << std::endl 
              << "SALARY: " << emp.salary << std::endl;
    std::cout << "Size struct: " << sizeof(emp) << std::endl;
    std::ofstream fout("name.txt");
    fout <<"ID: " << emp.id << std::endl
         << "AGE: " << emp.age << std::endl
         << "SALARY: " << emp.salary << std::endl;
    fout << "Size struct: " << sizeof(emp) << std::endl;

}