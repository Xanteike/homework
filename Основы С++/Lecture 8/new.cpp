#include "new.h"

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

void initField(Field& r)
{
	r.ppField = new Cell * [r.SIZE];
	for (size_t i = 0; i < r.SIZE; i++)
	{
		r.ppField[i] = new Cell[r.SIZE];
	}

	for (size_t y = 0; y < r.SIZE; y++)
	{
		for (size_t x = 0; x < r.SIZE; x++)
		{
			r.ppField[y][x] = Cell::EMPTY;
		}
	}

	if (getRandomNum(0, 1000) > 500)
	{
		r.human = Cell::CROSS;
		r.ai = Cell::ZERO;
		r.turn = 0;
	}
	else
	{
		r.human = Cell::ZERO;
		r.ai = Cell::CROSS;
		r.turn = 1;
	}
}

void deinitField(Field& r)
{
	for (size_t i = 0; i < r.SIZE; i++)
	{
		delete[] r.ppField[i];
	}
	delete[] r.ppField;
	r.ppField = nullptr;
}

void printField(const Field& r)
{
	cout << endl << "       ";
	for (size_t x = 0; x < r.SIZE; x++)
	{
		cout << x + 1 << "     ";
	}
	cout << endl;
	for (size_t y = 0; y < r.SIZE; y++)
	{
		cout << "     ----- ----- -----" << endl;
		cout << " " << y + 1 << "  |  ";
		for (size_t x = 0; x < r.SIZE; x++)
		{
			cout << static_cast<char> (r.ppField[y][x]) << "  |  ";
		}
		cout << endl;
	}
	cout << "     ----- ----- -----" << endl;
	cout << endl << "   Human: " << static_cast<char>(r.human) << endl;
	cout << "Computer: " << static_cast<char>(r.ai) << endl << endl;
}

void inline clearScr()
{
	system("cls");
}


Coord getHumanCoord(Field& f)
{
	Coord c;
	do
	{
		cout << "Enter x: ";
		cin >> c.x;
		cout << "Enter y: ";
		cin >> c.y;

		if (c.x == 0 || c.y == 0 || c.x <= 0 || c.y <= 0 || c.x > 3 || c.y > 3 || f.ppField[c.y - 1][c.x - 1] != Cell::EMPTY)
		{
			cerr << "Error! This cell is busy" << endl << endl;
		}
		Sleep(200);
	} while (c.x == 0 || c.y == 0 || c.x <= 0 || c.y <= 0 || c.x > 3 || c.y > 3 || f.ppField[c.y - 1][c.x - 1] != Cell::EMPTY);

	c.x--;
	c.y--;

	return c;
}

Coord getAICoord(Field& f)
{
	Coord arr[4] = { 0 };
	size_t num = 0;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == Cell::EMPTY)
			{
				f.ppField[y][x] = f.ai;
				if (getWon(f) == Progress::WON_AI)
				{
					f.ppField[y][x] = Cell::EMPTY;
					return { y, x };
				}
				f.ppField[y][x] = Cell::EMPTY;
			}
		}
	}

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == Cell::EMPTY)
			{
				f.ppField[y][x] = f.human;
				if (getWon(f) == Progress::WON_HUMAN)
				{
					f.ppField[y][x] = Cell::EMPTY;
					return { y, x };
				}
				f.ppField[y][x] = Cell::EMPTY;
			}
		}
	}

	if (f.ppField[1][1] == Cell::EMPTY)
	{
		return { 1, 1 };
	}

	if (f.ppField[0][0] == Cell::EMPTY)
	{
		arr[num++] = { 0, 0 };
	}
	if (f.ppField[2][2] == Cell::EMPTY)
	{
		arr[num++] = { 2, 2 };
	}
	if (f.ppField[0][2] == Cell::EMPTY)
	{
		arr[num++] = { 0, 2 };
	}
	if (f.ppField[2][0] == Cell::EMPTY)
	{
		arr[num++] = { 2, 0 };
	}

	if (num > 0)
	{
		const size_t index = getRandomNum(0, 500) % num;
		return arr[index];
	}

	num = 0;

	if (f.ppField[0][1] == Cell::EMPTY)
	{
		arr[num++] = { 0, 1 };
	}
	if (f.ppField[2][1] == Cell::EMPTY)
	{
		arr[num++] = { 2, 1 };
	}
	if (f.ppField[1][0] == Cell::EMPTY)
	{
		arr[num++] = { 1, 0 };
	}
	if (f.ppField[1][2] == Cell::EMPTY)
	{
		arr[num++] = { 1, 2 };
	}


	if (num > 0)
	{
		const size_t index = getRandomNum(0, 500) % num;
		return arr[index];
	}

	return { 1, 1 };
}

Progress getWon(const Field& f)
{
	for (size_t y = 0; y < f.SIZE; y++)
	{
		if (f.ppField[y][0] == f.ppField[y][1] && f.ppField[y][0] == f.ppField[y][2])
		{
			if (f.ppField[y][0] == f.ai)
			{
				return Progress::WON_AI;
			}
			else if (f.ppField[y][0] == f.human)
			{
				return Progress::WON_HUMAN;
			}
		}
	}

	for (size_t x = 0; x < f.SIZE; x++)
	{
		if (f.ppField[0][x] == f.ppField[1][x] && f.ppField[0][x] == f.ppField[2][x])
		{
			if (f.ppField[0][x] == f.ai)
			{
				return Progress::WON_AI;
			}
			else if (f.ppField[0][x] == f.human)
			{
				return Progress::WON_HUMAN;
			}
		}
	}

	for (size_t i = 0; i < f.SIZE; i++)
	{
		if (f.ppField[0][0] == f.ppField[1][1] && f.ppField[0][0] == f.ppField[2][2])
		{
			if (f.ppField[0][0] == f.ai)
			{
				return Progress::WON_AI;
			}
			else if (f.ppField[0][0] == f.human)
			{
				return Progress::WON_HUMAN;
			}
		}
	}


	for (size_t i = 0; i < f.SIZE; i++) 
	{
		if (f.ppField[2][0] == f.ppField[1][1] && f.ppField[1][1] == f.ppField[0][2])
		{
			if (f.ppField[1][1] == f.ai)
			{
				return Progress::WON_AI;
			}
			else if (f.ppField[1][1] == f.human)
			{
				return Progress::WON_HUMAN;
			}
		}
	}

	bool draw = true;
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == Cell::EMPTY)
			{
				draw = false;
				break;
			}
		}
		if (!draw)
		{
			break;
		}
	}

	if (draw)
	{
		return Progress::DRAW;
	}

	return Progress::IN_PROGRESS;
}

void congrats(Progress progress)
{
	if (progress == Progress::WON_HUMAN)
	{
		cout << "YOU WIN! :)" << endl
			<< "HUMAN WIN" << endl;
	}
	else if (progress == Progress::WON_AI)
	{
		cout << "YOU LOSE... :(" << endl
			<< "AI WIN" << endl;
	}
	else if (progress == Progress::DRAW)
	{
		cout << "DRAW :/" << endl;
	}

}

void TicTacToe()
{
	Field f;
	initField(f);
	clearScr();
	printField(f);
	do
	{
		if (f.turn % 2 == 0)
		{
			Coord c = getHumanCoord(f);
			f.ppField[c.y][c.x] = f.human;
		}
		else
		{
			Coord c = getAICoord(f);
			f.ppField[c.y][c.x] = f.ai;
		}
		f.turn++;
		clearScr();
		printField(f);
		f.progress = getWon(f);
		Sleep(400);
	} while (f.progress == Progress::IN_PROGRESS);
	congrats(f.progress);
	deinitField(f);
}