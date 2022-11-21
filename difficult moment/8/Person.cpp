#include "1.h"
#include "Person.h"

ostream& operator<<(ostream& stream, const Person& p)
{
    stream << p.surname << " " << p.name << " " << p.patronymic;
    return stream;
}

bool operator < (const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.patronymic) < tie(p2.surname, p2.name, p2.patronymic);
}

bool operator == (const Person& p1, const Person& p2)
{
    return tie(p1.surname, p1.name, p1.patronymic) == tie(p2.surname, p2.name, p2.patronymic);
}