#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;

//
// Выделить в памяти динамический одномерный массив
// типа int. Размер массива запросить у пользователя.
// Инициализировать его числами степенями двойки : 1, 2,
// 4, 8, 16, 32, 64, 128 … Вывести массив на экран
// Не забыть освободить память. = ) Разбить программу на функции.
//
const int max_size = 10;
void Task1()
{
    int* ptrArr;
    int write;
    cout << "Enter size of your array: ";
    cin >> write;
    ptrArr = new int[write];
    int temp = 1;
    if (write <= max_size)
    {
        cout << "Array: ";
        for (size_t i = 0; i < write; i++)
        {
            ptrArr[i] = temp;
            cout << ptrArr[i] << " ";
            temp *= 2;
        }
    }
    else if (write > max_size)
    {
        cerr << "Error! Enter a parameter of a smaller value" << endl;
        return Task1();
    }

    delete[] ptrArr;
}

//
// Динамически выделить матрицу 4х4 типа int.
// Инициализировать ее псевдослучайными числами через
// функцию rand.Вывести на экран.Разбейте вашу
// программу на функции которые вызываются из main.
//
const size_t SIZE = 3;
void Task2()
{
    int array[SIZE][SIZE];

    cout << "New random array" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            array[i][j] = rand() % 2 + 1;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

//
// Написать программу c 2 - я функциями, которая создаст
// два текстовых файла(*.txt), примерно по 50 - 100
// символов в каждом(особого значения не имеет с каким
// именно содержимым).Имена файлов запросить у польлзователя.
//
const size_t size_txt = 50;
int array_txt[size_txt];
string name1, name2, name_4;
string name3 = name_4 + ".txt";

void Task3_1()
{

    cout << "Enter name for first txt file: ";
    cin >> name1;
    ofstream fout(name1 + ".txt");
    fout << "Array to 50 nubmers" << endl;
    cout << "File name:" << name1 << ".txt" << endl;
    for (int i = 0; i < size_txt; i++)
    {
        array_txt[i] = rand();
        fout << array_txt[i] << " ";
        fout << endl;
    }
    fout.close();

}

void Task3_2()
{
    cout << "Enter name for second txt file: ";
    cin >> name2;
    ofstream fout(name2 + ".txt");
    cout << "File name:" << name2 << ".txt" << endl;
    fout << "Array to 50 nubmers" << endl;
    for (int i = 0; i < size_txt; i++)
    {
        array_txt[i] = rand();
        fout << array_txt[i] << " ";
        fout << endl;
        
    }
    fout.close();
}

void Task3()
{
    Task3_1();
    Task3_2();
}

//
// Написать функцию, «склеивающую» эти файлы в
// третий текстовый файл(имя файлов спросить у пользователя).
//
void Task4()
{
    cout << "Enter name for third txt file: ";
    cin >> name_4;
    ifstream in1(name1 + ".txt");
    ifstream in2(name2 + ".txt");
    ofstream out(name_4 + ".txt");
    string str1, str2;
    while (!in1.eof() || !in2.eof())
    {
        if (in1 >> str1)
            out << str1 << endl;
        if (in2 >> str2)
            out << str2 << endl;
    }
}

//
// Написать программу, которая проверяет
// присутствует ли указанное пользователем при запуске
// программы слово в указанном пользователем файле
// (для простоты работаем только с латиницей).
//
void Task5()
{
    ifstream out(name_4 + ".txt");
    string write;
    cout << "Enter a word / character to search for: ";
    cin >> write;
    cout << endl;
    if (name3.find(write) != string::npos)
    {
        cout << "You found the word!";
    }
    else
    {
        cout << "You didn't find the word :(";
    }
}


int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
}
