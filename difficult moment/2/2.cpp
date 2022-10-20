#include "1.h"
#include "2.h"

class Timer
{
private:
      using clock_t = std::chrono::high_resolution_clock;
      using second_t = std::chrono::duration<double, std::ratio<1> >;
 
      std::string m_name;
      std::chrono::time_point<clock_t> m_beg;
      double elapsed() const
      {
            return std::chrono::duration_cast<second_t>(clock_t::now() -m_beg).count();
      }
 
public:
      Timer() : m_beg(clock_t::now()) { }
      Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }
 
      void start(std::string name) {
            m_name = name;
            m_beg = clock_t::now();
      }
      void print() const {
            std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
      }
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

const std::string VOWEL_LETTERS = "аАеЕёЁиИоОуУэЭыЫюЮяЯ";

void CountIfAndCount(const std::string& s)
{
    Timer timer("------ Count_if and count ------");

    std::cout << std::endl << "Гласных букв: " <<
        std::count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            return std::count(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), currentChar);
        }) << std::endl;

    timer.print();
}

void CountIfAndFind(const std::string& s)
{
    Timer timer("------ Count_if and find ------");

    std::cout << std::endl << "Гласных букв: " <<
        std::count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            return std::find(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), currentChar) != VOWEL_LETTERS.end();
        }) << std::endl;

    timer.print();
}

void CountIfAndFor(const std::string& s)
{
    Timer timer("------ Count_if and for ------");

    std::cout << std::endl << "Гласных букв: " <<
        std::count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            for(auto i: VOWEL_LETTERS) {
                if(i == currentChar)
                    return true;
            }
            return false;
        }) << std::endl;

    timer.print();
}

void ForAndFind(const std::string& s)
{
    Timer timer("------ For and find ------");

    std::cout << std::endl << "Гласных букв: ";

    int cnt = 0;
    for(auto i: s) {
        if(std::find(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), i) != VOWEL_LETTERS.end())
            cnt++;
    }

    std::cout << cnt << std::endl;

    timer.print();
}

void ForAndFor(const std::string& s)
{
    Timer timer("------ For and for ------");

    std::cout << std::endl << "Гласных букв: ";

    int cnt = 0;
    for(auto tc: s) {
        for(auto vc: VOWEL_LETTERS) {
            if (tc == vc) {
                cnt++;
                break;
            }
        }
    }

    std::cout << cnt << std::endl;

    timer.print();
}

int main()
{
	return 0;
}