#include "1.h"
/////////////////// Task 1 /////////////////////

class pcout
{
public:
    pcout() : ulock(unique_lock<mutex>(mutex))
    {
    }

    template <typename T>
    pcout& operator<<(const T& data)
    {
        cout << data;
        return *this;
    }

    pcout& operator<<(ostream& (*os)(ostream&))
    {
        cout << os;
        return *this;
    }

private:
    static mutex mutex;
    unique_lock<mutex> ulock;
};

mutex pcout::mutex{};

void Task1()
{
    cout << "---------- pcout ----------" << endl;

    vector<jthread> pcout_threads;
    size_t threads(jthread::hardware_concurrency());

    for (size_t i = 0; i < threads; ++i) {
        pcout_threads.emplace_back([&]
            {
                pcout() << "pcout test in thread " << this_thread::get_id() << endl;
            });
    }
}

/////////////////// Task 2 /////////////////////

bool IsPrime(int64_t val)
{
    int64_t finish = sqrt(abs(val));
    for (int64_t i = 2; i <= finish; i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

int64_t GetSimpleNumber(int64_t limit)
{
    int64_t counter{0};
    int64_t index{2};

    for(index = 2, counter = 0; counter < limit; index++) {
        if(IsPrime(index)) {
            ++counter;
        }
    }

    return index;
}

void Task2()
{
    cout << "---------- N-th prime ----------" << endl;

    int64_t lim = 1000000;
    int64_t result{0};

    Timer timer("Primes");

    jthread t([&]{ result = GetSimpleNumber(lim); });
    t.join();
    cout << "Result: " << result << endl;

    timer.print();
}

/////////////////// Task 3 /////////////////////

void PrintVector(const auto& l)
{
    for_each(l.begin(), l.end(), [](const auto& v){ cout << v << " "; });
    cout << endl;
    cout << endl;
}

template<typename T>
T GetRandom(T minVal, T maxVal)
{
    random_device rd;
    static mt19937 ms(rd());
    if(is_floating_point_v<T>) {
        uniform_real_distribution<> uid(minVal, maxVal);
        return uid(ms);
    }

    uniform_int_distribution<> uid(minVal, maxVal);
    return uid(ms);
}

mutex storeMutex;

void HostPutToStore(vector<int>& store)
{
    this_thread::sleep_for(chrono::seconds(1));

    int item = GetRandom(1, 1000);
    lock_guard<mutex> lock(storeMutex);
    store.emplace_back(item);
    cout << "Хозяин кладет на склад " << item << endl;

    cout << "Содержимое склада: ";
    PrintVector(store);
}

void ThiefGetFromStore(vector<int>& store)
{
    this_thread::sleep_for(chrono::milliseconds(500));

    auto maxItem{max_element(execution::par, store.begin(), store.end())};
    if(maxItem != store.end()) {
        int item{*maxItem};
        lock_guard<mutex> lock(storeMutex);
        store.erase(maxItem);
        cout << "Вор крадет со склада " << item << endl;
    }

    cout << "Содержимое склада: ";
    PrintVector(store);
}

void Task3()
{
    vector<int> store{};

    for (size_t j{}; j < 30; ++j) {
        store.emplace_back(GetRandom(1, 1000));
    }

    for (size_t i{}; i < thread::hardware_concurrency(); ++i) {
        jthread host{HostPutToStore, ref(store)};
        jthread thief{ThiefGetFromStore, ref(store)};
    }
}