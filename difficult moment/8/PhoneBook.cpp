#include "1.h"
#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream& ifs)
{
    if(!ifs.is_open())
        throw "Ошибка! Файл не найден.";

    for(std::string line; std::getline(ifs, line); ) {
        std::stringstream ss(line);
        std::string tok{};
        int counter = 0;

        Person p;
        PhoneNumber pn;

        while(std::getline(ss, tok, ' ')) {
            if(counter == 0) {
                p.surname = tok;
                counter++;
                continue;
            }
            if(counter == 1) {
                p.name = tok;
                counter++;
                continue;
            }
            if(counter == 2) {
                if(tok[0]=='+') {
                    counter++;
                    pn.SetNumber(tok);
                    counter++;
                } else {
                    p.patronymic = tok;
                    counter++;
                }
                continue;
            }
            if(counter == 3) {
                pn.SetNumber(tok);
                counter++;
                continue;
            }
            if(counter == 4) {
                pn.SetAuxNumber(tok);
                counter++;
                continue;
            }
        }

        peoples.emplace_back(std::pair{p, pn});
    }
}

std::ostream& operator<<(std::ostream& stream, const PhoneBook& p)
{
    for(const auto& i: p.peoples) {
        stream << i.first << " " << i.second << std::endl;
    }
    return stream;
}

void PhoneBook::SortByName()
{
    std::sort(peoples.begin(), peoples.end());
}

void PhoneBook::SortByPhone()
{
    std::sort(peoples.begin(), peoples.end(), [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& s)
{
    std::tuple<std::string, PhoneNumber> ret;

    int j = 0;
    PhoneNumber pn;
    for(const auto& i: peoples) {
        if(i.first.surname == s) {
            j++;
            pn = i.second;
            if(j > 1) {
                return {"found more than 1", pn};
            }
        }
    }

    if(j == 1)
        return {"", pn};

    return {"not found", pn};
}

void PhoneBook::ChangePhoneNumber(Person p, PhoneNumber pn)
{
    for(auto& i: peoples) {
        if(i.first == p)
            i.second = pn;
    }
}
