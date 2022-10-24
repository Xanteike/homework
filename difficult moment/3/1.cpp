#include "1.h"

void arithmeticMean(list<float> &l)
{
    if (l.empty())
        return;

    float sum = .0f;

    for (auto f : l)
        sum += f;

    l.emplace_back(sum / l.size());
}

void Task1()
{
    list<float> lst{0.1f, 1.5f, 3, -0.2f};

    auto printList = [](const auto &l)
    {
        for (auto f : l)
            cout << f << " ";
        cout << endl;
    };

    printList(lst);
    arithmeticMean(lst);
    printList(lst);
}

int GetRandomInt(int minVal, int maxVal)
{
    random_device rd;
    static mt19937 ms(rd());
    uniform_int_distribution<> uid(minVal, maxVal);
    return uid(ms);
}

class Matrix
{
public:
    Matrix() = default;
    Matrix(size_t sz) : size(sz)
    {
        CreateMatrix();
    }

    ~Matrix()
    {
        for (size_t y = 0; y < size; y++)
            delete[] mat[y];

        delete[] mat;
    }

    void CreateMatrix()
    {
        mat = new int *[size];
        for (size_t y = 0; y < size; y++)
            mat[y] = new int[size];
    }

    void FillRandom()
    {
        for (size_t y = 0; y < size; y++)
            for (size_t x = 0; x < size; x++)
                mat[y][x] = GetRandomInt(1, 9);
    }

    void Print()
    {
        for (size_t y = 0; y < size; y++)
        {
            for (size_t x = 0; x < size; x++)
            {
                cout << mat[y][x] << " ";
            }
            cout << endl;
        }
    }

    int GetDeterminant()
    {
        if (!size)
            return 0;

        if (size == 1)
            return mat[0][0];

        if (size == 2)
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        int **matr = new int *[size];
        for (int y = 0; y < size; y++)
            matr[y] = new int[size];

        for (size_t y = 0; y < size; y++)
            for (size_t x = 0; x < size; x++)
                matr[y][x] = mat[y][x];

        int num1 = 0, num2 = 0, det = 1, total = 1;
        size_t index = 0;

        int temp[size + 1];

        for (size_t i = 0; i < size; i++)
        {
            index = i;
            while (matr[index][i] == 0 && index < size)
            {
                index++;
            }
            if (index == size)
            {
                continue;
            }
            if (index != i)
            {
                for (int j = 0; j < size; j++)
                {
                    swap(matr[index][j], matr[i][j]);
                }
                det = det * pow(-1, index - i);
            }

            for (int j = 0; j < size; j++)
            {
                temp[j] = matr[i][j];
            }

            for (int j = i + 1; j < size; j++)
            {
                num1 = temp[i];
                num2 = matr[j][i];

                for (int k = 0; k < size; k++)
                {
                    matr[j][k] = (num1 * matr[j][k]) - (num2 * temp[k]);
                }
                total = total * num1;
            }
        }

        for (int i = 0; i < size; i++)
        {
            det = det * matr[i][i];
        }

        for (size_t y = 0; y < size; y++)
            delete[] matr[y];

        delete[] matr;

        return (det / total);
    }

private:
    size_t size{3};
    int **mat{};
};

void Task2()
{
    Matrix mat(4);
    mat.FillRandom();
    cout << mat.GetDeterminant() << endl;
}

template <typename T>
class MyContainer;

template <typename T>
class MyIterator : public iterator<input_iterator_tag, T>
{
    friend class MyContainer<T>;

public:
    MyIterator(const MyIterator &it) : p(it.p){};

    bool operator!=(MyIterator const &other) const { return p != other.p; };
    bool operator==(MyIterator const &other) const { return p == other.p; };
    typename MyIterator::reference operator*() const { return *p; };
    MyIterator &operator++()
    {
        p++;
        return *this;
    };
    MyIterator &operator--()
    {
        p--;
        return *this;
    };

private:
    MyIterator(T *p) : p(p){};

private:
    T *p;
};

template <typename T>
class MyContainer
{
public:
    typedef MyIterator<T> iterator;
    typedef MyIterator<const T> const_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;
    typedef reverse_iterator<const_iterator> const_reverse_iterator;

    iterator begin() { return iterator(data); };
    iterator end() { return iterator(data + size()); };
    const_iterator begin() const { return const_iterator(data); };
    const_iterator end() const { return const_iterator(data + size()); };

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    const_iterator cbegin() const { return const_iterator(data); };
    const_iterator cend() const { return const_iterator(data + size()); };
    const_reverse_iterator crbegin() const { return const_reverse_iterator(end()); }
    const_reverse_iterator crend() const { return const_reverse_iterator(begin()); }

    size_t size() const { return length; }

public:
    MyContainer() = default;

    MyContainer(size_t len) : length(len)
    {
        data = new T[length];
    }

    MyContainer(const initializer_list<T> &l) : MyContainer(l.size())
    {
        size_t idx = 0;
        for (auto &e : l)
        {
            data[idx++] = e;
        }
    }

    ~MyContainer()
    {
        delete[] data;
    }

    T &operator[](size_t index)
    {
        return data[index];
    }

    T &at(size_t index)
    {
        if (index >= 0 && index <= length)
            return data[index];

        throw "Index out of range.";
    }

private:
    size_t length{};
    T *data{};
};

void Task3()
{
    MyContainer<int> arr{1, 2, 3, 4, 5, 6};

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    cout << arr.at(2) << endl;

    for (auto p = arr.begin(); p != arr.end(); ++p)
        cout << *p << " ";
    cout << endl;

    for (auto p = arr.rbegin(); p != arr.rend(); ++p)
        cout << *p << " ";
    cout << endl;
}