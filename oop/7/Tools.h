#pragma once

template<typename T>
T GetUserInput(const string& prompt, int length = 1)
{
    while(true) {
        T val;

        cout << prompt << ": ";
        cin >> val;

        if (cin.fail() || (to_string(val).length() > length && !is_same<T, char>::value)) {
            cin.clear();
            cin.ignore(numeric_limits<T>::max(), '\n');
            cout << "Incorrect input. Try again." << endl;
        } else {
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
