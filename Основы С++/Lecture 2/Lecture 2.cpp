#include <iostream>

using namespace std;

void Task1() 
{

	short int a = 10;	
	int b = 200;
	long long c = 30454126758;
	char d = 'C';
	bool e = true;
	double g = 3.14159;
	float f = 7.8f;

	cout << " Short int: " << a << endl
		<< " Int: " << b << endl
		<< " long long: " << c << endl
		<< " Char: " << d << endl
		<< " Bool " << e << endl
		<< " Double " << f << endl
		<< " Float: " << g << endl;

};

const enum class Cell : char
{
	CROSS = 'X',
	ZERO = 'O',
	EMPTY = ' '
};

Cell cell_array[] = { Cell::CROSS, Cell::ZERO, Cell::EMPTY };

struct Field
{
	const size_t SIZE = 3;
	Cell human = Cell::EMPTY;
	Cell AI = Cell::EMPTY;
	size_t turn = 0;
};

void Task3() 
{
	struct Variants
	{
		union VariantsType
		{
			int myInt;
			float myFloat;
			char myChar;
		};

		VariantsType var;
		char isInt : 1;
		char isFloat : 1;
		char isChar : 1;

		void operator =(int p) { var.myInt = p; isInt = 1; isFloat = 0; isChar = 0; }
		void operator =(float p) { var.myFloat = p; isInt = 0; isFloat = 1; isChar = 0; }
		void operator =(char p) { var.myChar = p; isInt = 0; isFloat = 0; isChar = 1; }

	};

}

int main() 
{
	Task1();
    Task3();
}