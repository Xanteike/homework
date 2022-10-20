#include "1.h"
#include "2.h"

class Timer
{
private:
      using clock_t = chrono::high_resolution_clock;
      using second_t = chrono::duration<double, ratio<1> >;
 
      string m_name;
      chrono::time_point<clock_t> m_beg;
      double elapsed() const
      {
            return chrono::duration_cast<second_t>(clock_t::now() -m_beg).count();
      }
 
public:
      Timer() : m_beg(clock_t::now()) { }
      Timer(string name) : m_name(name), m_beg(clock_t::now()) { }
 
      void start(string name) {
            m_name = name;
            m_beg = clock_t::now();
      }
      void print() const {
            cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
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
	cout << "Enter x = ";
	cin >> x;
	cout << "Enter y = ";
	cin >> y;
	cout << endl << "Swap x and y:" << endl;
	Swap(&x, &y);
	cout << "x = " << x << endl << "y = " << y << endl;
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

const string VOWEL_LETTERS = "аАеЕёЁиИоОуУэЭыЫюЮяЯ";

void CountIfAndCount(const string& s)
{
    cout << endl << "Гласных букв: " <<
        count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            return count(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), currentChar);
        }) << endl;
}

void CountIfAndFind(const string& s)
{

    cout << endl << "Гласных букв: " <<
        count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            return find(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), currentChar) != VOWEL_LETTERS.end();
        }) << endl;
}

void CountIfAndFor(const string& s)
{
	 cout << endl << "Гласных букв: " <<
        count_if(s.begin(), s.end(), [](char currentChar) -> bool
        {
            for(auto i: VOWEL_LETTERS) {
                if(i == currentChar)
                    return true;
            }
            return false;
        }) << endl;
}


void ForAndFind(const string& s)
{
 cout << endl << "Гласных букв: ";

    int cnt = 0;
    for(auto i: s) {
        if(find(VOWEL_LETTERS.begin(), VOWEL_LETTERS.end(), i) != VOWEL_LETTERS.end())
            cnt++;
    }
}

void ForAndFor(const string& s)
{
 cout << endl << "Гласных букв: ";

    int cnt = 0;
    for(auto tc: s) {
        for(auto vc: VOWEL_LETTERS) {
            if (tc == vc) {
                cnt++;
                break;
            }
        }
    }
}

int main()
{
	return 0;
}