#include <iostream>

using namespace std;

void Task1()
{
	int a, b, c;
	cout << "Write two numbers and press enter";
	cin >> a >> b;
	c = a + b;
	if (c >= 10 && c <= 20) 
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}

void Task2()
{
	int a, b, c;

	cin >> a >> b;
	c = a + b;
	cout << "Write two numbers and press enter";
	if ( a == 10 || b == 10 || c == 10 )
	{
		cout << "true" << endl;
	}
	else 
	{
		cout << "false" << endl;
	}
}

void Task3()
{
	const size_t SIZE = 50;
	int numbers[SIZE] = {};
	cout << "Your odd numbers: ";
	for (size_t i = 1; i <= SIZE; i += 2)
	{
		cout << i << " ";
	}
}

void Task4() {
	int a;
	cout << "Write a simple or complex number: ";
	cin >> a;
	if ( a < 2 ) 
	{
		cout << "This complex or negative number";
	}
	else if ( a % 1 == 0 && a / a )
	{
		cout << " This simple number " << endl;
	}
}

bool Task5(const int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}






int main()
{
	Task1();
	Task2();
	Task3();
	Task4();
	// task 5
	int year;
	cout << "Enter year:\n";
	cin >> year;
	if (Task5(year))
	{
		cout << "Year is leap";
	}
	else
	{
		cout << "Not a leap year";
	}
	return 0;
}
