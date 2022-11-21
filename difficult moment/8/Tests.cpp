#include "1.h"

class PersonTest : public testing::Test
{
protected:
    void SetUp() override
    {
        person = new Person("Ivanov", "Ivan", "Ivanovich");
    }
    void TearDown() override {
        delete person;
    }
    Person* person;
};

TEST_F(PersonTest, strings){
    ASSERT_STREQ(person->name.c_str(), "Ivan");
    ASSERT_STREQ(person->surname.c_str(), "Ivanov");
    ASSERT_STREQ(person->patronymic.c_str(), "Ivanovich");
}

TEST_F(PersonTest, operators){
    ASSERT_EQ(Person("Ivanov", "Ivan", "Ivanovich"),Person("Ivanov", "Ivan", "Ivanovich"));
}

class PhoneNumberTest : public testing::Test
{
protected:
    void SetUp() override
    {
        phone = new PhoneNumber("+7(777)7777777", 77);
        phone2 = new PhoneNumber(8, 888, "8888888", 88);
    }
    void TearDown() override {
        delete phone;
        delete phone2;
    }
    PhoneNumber* phone;
    PhoneNumber* phone2;
};

TEST_F(PhoneNumberTest, phone){
    ASSERT_EQ(phone->countryCode, 7);
    ASSERT_EQ(phone->cityCode, 777);
    ASSERT_EQ(phone->number, "7777777");
    ASSERT_EQ(phone->auxNumber, 77);

    stringstream s;
    s << *phone2;
    ASSERT_EQ(s.str(), "+8(888)8888888 88");
    ASSERT_STREQ(s.str().c_str(), "+8(888)8888888 88");
}

int Tests()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}