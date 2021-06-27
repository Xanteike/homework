int a = 1;
int b = 3;
int c = 10;
int d = 2;

void Task1()
{
	int abc = a * (b + (c / static_cast<float>(d)));;
	cout << "Expression:  a * (b + (c / d))" << endl << "Write 4 variables after each press Enter: " << endl;
	cin >> a >> b >> c >> d;
	cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
	cout << "Result: " << abc << endl;
};

void Task2()
{
	int g;
	cout << "Enter any integer value: ";
	cin >> g;
	int h = (g <= 21) ? 21 - g : (21 - g) * 2;
	cout << "Result: " << h << endl;
};

void Task3()
{
	int game[3][3][3] = { Boo::ZERO };

	int* ptr = nullptr;
	ptr = &game[0][0][0];
	*(ptr + 13) = 1;
	cout << "Value of cell at [1][1][1] - " << game[1][1][1] << endl;
	cout << "Address of massive is " << &ptr << endl;
};