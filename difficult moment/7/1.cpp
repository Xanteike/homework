#include "2.h"

void StudentsGroup::Open()
{
    std::ifstream ifs { fileName, std::ios_base::binary };

    if(!ifs.is_open()) {
        throw std::runtime_error { "Не могу открыть файл " + fileName };
    }

    if(!(studentsGroup.ParseFromIstream(&ifs))) {
        throw std::runtime_error { "Не могу прочитать файл " + fileName };
    }

    std::cout << "Прочтено из файла студентов в группе: " << studentsGroup.students_size() << std::endl;
}

void StudentsGroup::Save()
{
    std::ofstream ofs { fileName, std::ios_base::binary };

    if(!ofs.is_open()) {
        throw std::runtime_error { "Не могу открыть файл " + fileName };
    }

    if(!(studentsGroup.SerializeToOstream(&ofs))) {
        throw std::runtime_error { "Не могу записать в файл " + fileName };
    }

    std::cout << "Записано студентов в файл: " << studentsGroup.students_size() << std::endl;
}

double StudentsGroup::GetAverageScore(const Lesson7::FullName& name)
{
    for(auto i : studentsGroup.students()) {
        if(i.fullname() == name) {
            return i.averagescore();
        }
    }
    return -1.0;
}

std::string StudentsGroup::GetAllInfo(const Lesson7::FullName& name)
{
    std::stringstream ret{};

    for(auto i : studentsGroup.students()) {
        if(i.fullname() == name) {
            ret << "Ф.И.О.: " << i.fullname().surname() << " " << i.fullname().name() << " "  << i.fullname().patronymic();
            ret << " Средний бал: " << i.averagescore();
            ret << std::endl;
            return ret.str();
        }
    }

    return "Студент не найден.";
}

std::string StudentsGroup::GetAllInfo()
{
    std::stringstream ret{};
    for (auto i : studentsGroup.students()) {
        ret << "Ф.И.О.: " << i.fullname().surname() << " " << i.fullname().name() << " "  << i.fullname().patronymic();
        ret << " Средний бал: " << i.averagescore();
        ret << std::endl;

    }
    return ret.str();
}

template<typename T>
T GetRandom(T minVal, T maxVal)
{
    std::random_device rd;
    static std::mt19937 ms(rd());
    if(std::is_floating_point_v<T>) {
        std::uniform_real_distribution<> uid(minVal, maxVal);
        return uid(ms);
    }

    std::uniform_int_distribution<> uid(minVal, maxVal);
    return uid(ms);
}

void Task1()
{
    StudentsGroup sg;

    for(int i{1}; i <= 10; ++i) {
        Lesson7::FullName fn;
        Lesson7::Student s;
        fn.set_surname("Ivanov" + std::to_string(i));
        fn.set_name("Ivan" + std::to_string(i));
        fn.set_patronymic("Ivanovich" + std::to_string(i));
        *s.mutable_fullname() = fn;
        int r = GetRandom(1, 8);
        for(int i = 0; i < r; ++i)
            s.add_scores(GetRandom(1, 10));
        s.set_averagescore(std::accumulate(s.scores().begin(), s.scores().end(), 0.0) / s.scores().size());
        sg.Add(s);
    }

    sg.Save();

    sg.Open();
    std::string allinfo = sg.GetAllInfo();
    std::cout << allinfo << std::endl;

    {
        std::cout << "Ищем студента Ivanov5 Ivan5 Ivanovich5" << std::endl;
        Lesson7::FullName fn;
        fn.set_surname("Ivanov5");
        fn.set_name("Ivan5");
        fn.set_patronymic("Ivanovich5");
        std::string allinfo2 = sg.GetAllInfo(fn);
        std::cout << allinfo2 << std::endl;
    }

    {
        std::cout << "Ищем не существующего студента Ivanov55 Ivan5 Ivanovich5" << std::endl;
        Lesson7::FullName fn;
        fn.set_surname("Ivanov55");
        fn.set_name("Ivan5");
        fn.set_patronymic("Ivanovich5");
        std::string allinfo2 = sg.GetAllInfo(fn);
        std::cout << allinfo2 << std::endl << std::endl;
    }

    {
        std::cout << "Средний бал студента Ivanov8 Ivan8 Ivanovich8: ";
        Lesson7::FullName fn;
        fn.set_surname("Ivanov8");
        fn.set_name("Ivan8");
        fn.set_patronymic("Ivanovich8");
        std::cout << sg.GetAverageScore(fn) << std::endl;
        std::cout << std::endl;
    }
}