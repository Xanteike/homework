#pragma once

#include "1.h"
#include "3.proto"

class IRepository
{
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods
{
    virtual double GetAverageScore(const Lesson7::FullName& name) = 0;
    virtual std::string GetAllInfo(const Lesson7::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, public IMethods
{
public:
    virtual void Open() override;
    virtual void Save() override;

    virtual double GetAverageScore(const Lesson7::FullName& name) override;
    virtual std::string GetAllInfo(const Lesson7::FullName& name) override;
    virtual std::string GetAllInfo() override;

    StudentsGroup() = default;
    StudentsGroup(const std::string& fname) : fileName(fname) {};

    void Add(const Lesson7::Student& stud)
    {
        studentsGroup.add_students()->CopyFrom(stud);
    }

private:
    Lesson7::StudentsGroup studentsGroup;
    std::string fileName { "studentsGroup.bin" };
};

inline bool operator == (const Lesson7::FullName& p1, const Lesson7::FullName& p2)
{
    return std::tie(p1.surname(), p1.name(), p1.patronymic()) == std::tie(p2.surname(), p2.name(), p2.patronymic());
}
