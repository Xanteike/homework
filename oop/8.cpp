#include <iostream>
#include <string>



using namespace std;

class Lesson
{
public:
    void Task1();
    void Task2();
    void Task3();
};

template<typename T>
T GetUserInput(const string& prompt)
{
    while (true) {
        T val;

        cout << prompt << ": ";
        cin >> val;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<T>::max(), '\n');
            cout << "Incorrect input. Try again." << endl;
        }
        else {
            cin.ignore(numeric_limits<T>::max(), '\n');
            return val;
        }
    }
}

inline ostream& endll(ostream& stream)
{
    stream << "\n\n" << flush;
    return stream;
}

inline int EnterNumber(const string& prompt)
{
    int input;
    while (true)
    {
        cout << prompt << ": " << flush;
        string line;
        if (!getline(cin, line)) {
            cerr << "Critical error!!!" << endl;
            return numeric_limits<int>::min();
        }
        istringstream line_stream(line);
        char extra;
        if (line_stream >> input && !(line_stream >> extra))
            break;
        else
            cout << "Invalid input. Repeat." << endl;
    }
    cout << input << endl;
    return input;
}
class DivisionByZeroException
{
public:
    DivisionByZeroException(const string& msg = "", const string& file = "", int line = 0) :
        message(msg),
        fileName(file),
        lineNumber(line)
    {
        fullMessage = "Fail: " + message + " (File: " + fileName + ", line: " + to_string(lineNumber) + ")";
    }

    virtual const string& GetMessage() const
    {
        return fullMessage;
    }

protected:
    string fullMessage{};
    string message{};
    string fileName{};
    int lineNumber{ 0 };
};

template <typename T>
double Div(T a, T b)
{
    if (b == 0)
        throw DivisionByZeroException("sdfsdfsd\n sdfsdfsdf\n sdfsdfsdfsd\n sdfsdfsdf\n", __FILE__, __LINE__);

    return a / b;
}

void Lesson::Task1()
{

    try
    {
        double result = Div(10, 0);
        cout << result << endl;
    }
    catch (const DivisionByZeroException& e)
    {
        cout << e.GetMessage();
    }

    cout << endll;
}


class Ex
{
public:
    Ex(double X) : x(X) {};

public:
    double x;
};

class Bar
{
public:
    Bar(double Y = 0.0) : y(Y) {}

    void Set(double a)
    {
        if ((y + a) > 100)
            throw Ex(a * y);
        else
            y = a;
    }

private:
    double y;
};

void Lesson::Task2()
{

    Bar a;
    int b;

    try {
        while (true) {
            b = GetUserInput<int>("Enter an integer");
            if (b == 0)
                break;
            a.Set(b);
        }
    }
    catch (const Ex& e)
    {
        cout << e.x << endl;
    }

    cout << endl;
}

const int CELL_SIZE = 10;

class RobotException
{
public:
    RobotException(int curX, int curY, int newX, int newY) :
        currentPositionX(curX),
        currentPositionY(curY),
        newPositionX(newX),
        newPositionY(newY),
        message("")
    {}

    const string& GetInfo() const
    {
        return message;
    }

    const string& GetCoordinates()
    {
        coords = "from (" +
            to_string(currentPositionX) + ", " + to_string(currentPositionY) +
            ") in (" +
            to_string(newPositionX) + ", " + to_string(newPositionY) + ")";

        return coords;
    }

protected:
    int currentPositionX{ 0 };
    int currentPositionY{ 0 };
    int newPositionX{ 0 };
    int newPositionY{ 0 };
    string message{};
    string coords{};
};

class OffTheField : public RobotException
{
public:
    OffTheField(int curX, int curY, int newX, int newY) :
        RobotException(curX, curY, newX, newY)
    {
        if (newPositionX > CELL_SIZE || newPositionX < 1) {
            message = "The error of going beyond the boundaries on the X axis " + GetCoordinates();
        }

        if (newPositionY > CELL_SIZE || newPositionY < 1) {
            message = "Error of going beyond the boundaries on the Y axis" + GetCoordinates();
        }
    }
};

class IllegalCommand : public RobotException
{
public:
    IllegalCommand(int curX, int curY, int newX, int newY) :
        RobotException(curX, curY, newX, newY)
    {
        if (abs(currentPositionX - newPositionX) > 1) {
            message = "The X-axis step is too large" + GetCoordinates();
        }

        if (abs(currentPositionY - newPositionY) > 1) {
            message = "The Y-axis step is too large " + GetCoordinates();
        }

        if (currentPositionX == newPositionX && currentPositionY == newPositionY) {
            message = "You can't go to the place where you are " + GetCoordinates();
        }
    }
};

class Robot
{
public:
    Robot(int x = CELL_SIZE / 2, int y = CELL_SIZE / 2) :
        positionX(x),
        positionY(y)
    {
        cout << "We start in the position " << positionX << ", " << positionY << endl;
    }

    void Move(int x, int y)
    {
        if (abs(positionX - x) > 1 || abs(positionY - y) > 1 || (positionX == x && positionY == y))
            throw IllegalCommand(positionX, positionY, x, y);
        if (x > CELL_SIZE || x < 1 || y > CELL_SIZE || y < 1)
            throw OffTheField(positionX, positionY, x, y);

        cout << "Let 's go from (" << positionX << ", " << positionY << ") в (" << x << ", " << y << ")" << endl;

        positionX = x;
        positionY = y;
    }

private:
    int positionX{};
    int positionY{};
};

void Lesson::Task3()
{

    int x = 0, y = 0;
    Robot robot;

    while (true) {
        cout << "Enter 0 in X and Y to exit." << endl;
        x = GetUserInput<int>("Enter the position by X");
        y = GetUserInput<int>("Enter the position by Y");

        if (x == 0 && y == 0)
            break;

        try {
            robot.Move(x, y);
        }
        catch (const IllegalCommand& e) {
            cout << e.GetInfo() << endl;
        }
        catch (const OffTheField& e) {
            cout << e.GetInfo() << endl;
        }
    }
}
