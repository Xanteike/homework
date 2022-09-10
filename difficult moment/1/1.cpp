#include "1.h"

struct Person
{
	string firstName;
	string lastName;
	optional <string> middleName;
};

bool operator<(const Person& a, const Person& b)
{
	return std::tie(a.firstName, a.lastName, a.middleName) < std::tie(b.firstName, b.lastName, b.middleName);
}

bool operator==(const Person& a, const Person& b)
{
	return std::tie(a.firstName, a.lastName, a.middleName) == std::tie(b.firstName, b.lastName, b.middleName);
}

ostream& operator<<(ostream& out, const Person& a)
{
	out << setw(15) << a.firstName << setw(12) << a.lastName;

	if (a.middleName.has_value())
	{
		out << setw(15) << a.middleName.has_value();
	}
	else
	{
		out << setw(18);
	}

	return out;
}

struct PhoneNumber
{
	int countryCode;
	int cityCode;
	string number;
	optional <int> additionalNumber;
};

bool operator<(const PhoneNumber& a, const PhoneNumber& b)
{
	return std::tie(a.countryCode, a.cityCode, a.number, a.additionalNumber) < std::tie(b.countryCode, b.cityCode, b.number, b.additionalNumber);
}

bool operator==(const PhoneNumber& a, const PhoneNumber& b)
{
	return std::tie(a.countryCode, a.cityCode, a.number, a.additionalNumber) == std::tie(b.countryCode, b.cityCode, b.number, b.additionalNumber);
}

ostream& operator<<(ostream& out, const PhoneNumber& a)
{
	out << setw(3) << "+" << a.countryCode << "(" << a.cityCode << ")" << a.number;

	if (a.additionalNumber.has_value())
	{
		out << " " << a.additionalNumber.has_value();
	}

	return out;
}

optional<int> getOptInt(string& a)
{
	if (a == "")
	{
		return nullopt;
	}
	return stoi(a);
}

optional<string> getOptStr(string& a)
{
	if (a == "")
	{
		return nullopt;
	}
	return a;
}

class PhoneBook
{
private:
	vector<pair<Person, PhoneNumber>> m_data;

public:
	PhoneBook(ifstream& file)
	{
		if (!file)
		{
			std::cout << "Can`t find the file" << std::endl;
			exit(-1);
		}

		for (string line; getline(file, line);)
		{
			stringstream str(line);
			vector<string> rowData;

			for (string s; getline(str, s, ';');)
			{
				rowData.push_back(s);
			}

			pair<Person, PhoneNumber> entry;

			for (size_t i = 0; i < rowData.size(); ++i)
			{
				switch (i)
				{
				case 0:
					entry.first.firstName = rowData[i];
					break;
				case 1:
					entry.first.lastName = rowData[i];
					break;
				case 2:
					entry.first.middleName = getOptStr(rowData[i]);
					break;
				case 3:
					entry.second.countryCode = stoi(rowData[i]);
					break;
				case 4:
					entry.second.cityCode = stoi(rowData[i]);
					break;
				case 5:
					entry.second.number = rowData[i];
					break;
				case 6:
					entry.second.additionalNumber = getOptInt(rowData[i]);
					break;
				}
			}
			m_data.push_back(entry);
		}
	}

	friend ostream& operator<<(ostream& out, const PhoneBook& a)
	{
		for (const auto& [first, second] : a.m_data)
		{
			out << first << " " << second << endl;
		}

		return out;
	}

	void SortByName()
	{
		sort(m_data.begin(), m_data.end(), [](const pair<Person, PhoneNumber>& lhs, const pair<Person, PhoneNumber>& rhs)
			{
				return lhs.first < rhs.first;
			});
	}

	void SortByPhone()
	{
		sort(m_data.begin(), m_data.end(), [](const pair<Person, PhoneNumber>& lhs, const pair<Person, PhoneNumber>& rhs)
			{
				return lhs.second < rhs.second;
			});
	}

	pair<string, vector<PhoneNumber>> getPhoneNumber(const string& fistname)
	{
		vector <PhoneNumber> phoneNumbers;
		int count = 0;

		for_each(m_data.begin(), m_data.end(), [&](const auto& entry)
			{
				if (entry.first.firstName == fistname)
				{
					phoneNumbers.push_back(entry.second);
					++count;
				}
			});

		switch (count)
		{
		case 0:
			return { "not found", phoneNumbers };
		case 1:
			return { "", phoneNumbers };
		default:
			return { "found more than 1", phoneNumbers };
		}
	}

	void changePhoneNumber(const Person& p, const PhoneNumber& pn)
	{
		auto entry = find_if(m_data.begin(), m_data.end(), [&](const auto& entry)
			{
				return entry.first == p;
			});

		if (entry != m_data.end())
		{
			entry->second = pn;
		}
	}


};

int main()
{
	ifstream file("PhoneBook.txt");
	PhoneBook book(file);
	cout << book;

	cout << "------SortByPhone-------" << endl;
	book.SortByPhone();
	cout << book;

	cout << "------SortByName--------" << endl;
	book.SortByName();
	cout << book;

	cout << "-----GetPhoneNumber-----" << endl;
	// лямбда функция, которая принимает фамилию и выводит номер телефона этого     человека, либо строку с ошибкой
	auto print_phone_number = [&book](const string& surname)
	{
		cout << surname << "\t";
		auto answer = book.getPhoneNumber(surname);
		if (get<0>(answer).empty())
		{
			for (size_t i = 0; i < get<1>(answer).size(); ++i)
			{
				cout << get<1>(answer)[i];
			}
		}
		else
		{
			cout << get<0>(answer);
		}
		cout << endl;
	};

	// вызовы лямбды
	print_phone_number("Ivanov");
	print_phone_number("Petrov");

	cout << "----ChangePhoneNumber----" << endl;
	book.changePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
	book.changePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
	cout << book;

	return 0;
}
