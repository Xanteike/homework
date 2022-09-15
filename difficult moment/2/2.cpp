#include "1.h"
#include "2.h"

class Timer
{
private:

public:
};

template<typename T>
void Swap(T* a, T* b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}


void PrintSwap()
{
	int x, y;
	std::cout << "Enter x = ";
	std::cin >> x;
	std::cout << "Enter y = ";
	std::cin >> y;
	std::cout << std::endl << "Swap x and y:" << std::endl;
	Swap(&x, &y);
	std::cout << "x = " << x << std::endl << "y = " << y << std::endl;
}

template<typename T>
void SortPoint(vector<T*>& vec)
{
	sort(vec.begin(), vec.end(), [](const auto& vec1, const auto& vec2)
	{
			return *vec1 < *vec2;
	});

}

void task2()
{
	int abc = 1;
	vector <int*> vec;
	for (int i = 0; i < abc; ++i)
	{
		int* a = new int;
		*a = rand() % 10;
		vec.push_back(a);
	}
	SortPoint(vec);
}

int main()
{
	PrintSwap(); // task1
	return 0;
}