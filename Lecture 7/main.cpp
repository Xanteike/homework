#include "mylib.h"

int main()
{
    // --------------Task1/Task5-------------
    const size_t size_array = 5;
    float array[size_array];
    MyLib::cinArray(array, size_array);
    MyLib::printArray(array, size_array);
    MyLib::countingArray(array, size_array);

    // --------------Task2-------------------
    Task2();
    // --------------Task3-------------------
    Task4();
    Task3();
    // --------------Task4-------------------
    Task4();

}