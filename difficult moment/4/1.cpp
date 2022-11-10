#include "1.h"

template<typename T>
void insert_sorted(vector<T>& vec, const T& val)
{
    auto ret = find_if(vec.begin(), vec.end(),[&val](const T& v) { return v >= val; });
    if(ret != vec.end())
        vec.insert(ret,val);
    else
        vec.emplace_back(val);
}

void PrintVector(const auto& l)
{
    for_each(l.begin(), l.end(), [](const auto& v){ cout << v << " "; });
    cout << endl;
}

void Task1()
{
    vector<int> v{1, 2, 3, 4, 7, 8, 9};
    PrintVector(v);
    insert_sorted(v, 5);
    PrintVector(v);
    insert_sorted(v, 15);
    PrintVector(v);
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

void Task2()
{
const size_t VECTOR_SIZE = 100;

    vector<double> analogSignal(VECTOR_SIZE);
    vector<int> digitalSignal(VECTOR_SIZE);
    vector<double> deltas(VECTOR_SIZE);

    generate(analogSignal.begin(), analogSignal.end(), []() { return GetRandom(-100.0, 100.0); });
    cout << "Analog signal: ";
    PrintVector(analogSignal);

    transform(analogSignal.begin(),analogSignal.end(),digitalSignal.begin(),[](double& v)->int {return static_cast<int>(v);});
    cout << "Digital signal: ";
    PrintVector(digitalSignal);

    transform(analogSignal.begin(),analogSignal.end(),digitalSignal.begin(),deltas.begin(),
        [](const double& as, const int &ds)->double {
        return static_cast<double>((as-ds)*(as-ds));
    });

    cout << "Deltas: ";
    PrintVector(deltas);

    cout << "Error: " << std::accumulate(deltas.begin(),deltas.end(),0.0) << endl;

}