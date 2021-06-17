#pragma once

#include <iostream>
#include <string>
#include <fstream>
// --------------------------------------------------Task1/5-----------------------------------------
namespace MyLib 
{
	void printArray(float arr[], const int size);
	void cinArray(float arr[], const int size);
	void countingArray(float arr[], const int size);
}
// --------------------------------------------------Task2-----------------------------------------
void Task2();
// --------------------------------------------------Task3-----------------------------------------
void Task3print(int* arr, int size);
void Task3Sort(int* arr, int size);
void Task3();
// --------------------------------------------------Task4-----------------------------------------

#pragma pack(push,1)
	struct Employee
	{
		int id;
		int age;
		double salary;
	};
#pragma pack(pop)
	void Task4();