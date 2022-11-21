#include "1.h"

void Lesson()
{
    std::string fname="./PhoneBook.txt";

    if(fname.empty())
        throw "Ошибка! Укажите имя файла.";

    std::ifstream ifs(fname);
    PhoneBook pb(ifs);

    std::cout << pb;
    std::cout << std::endl;

    std::cout << "------SortByName--------" << std::endl;
    pb.SortByName();
    std::cout << pb;
    std::cout << std::endl;

    std::cout << "------SortByPhone-------" << std::endl;
    pb.SortByPhone();
    std::cout << pb;
    std::cout << std::endl;

    std::cout << "-----GetPhoneNumber-----" << std::endl;

    auto print_phone_number = [&pb](const std::string& surname) {
        std::cout << surname << "\t";
        auto answer = pb.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            std::cout << get<1>(answer);
        else
            std::cout << get<0>(answer);
        std::cout << std::endl;
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    print_phone_number("Kim");

    std::cout << "----ChangePhoneNumber----" << std::endl;
    pb.ChangePhoneNumber(Person{ "Markelov", "Dmitriy", "Vadimovich" }, PhoneNumber{7, 123, "15344458"});
    pb.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << pb;
}