#include <catch2/catch_test_macros.hpp>
#include "../istudhub/istudyinggroup.hpp"
#include "../myapp/myapp.hpp"
#include "../dailybudget/dailybudget.cpp"
#include "../eveningbudget/eveningbudget.cpp"
#include "../feepaying/feepaying.cpp"


TEST_CASE("DailyBudget group")
{
    SECTION("Constructors")
    {
        DailyBudget a(1, 3, 4, DailyBudget::Specialization::AMCS, 5, 6);
        REQUIRE(a.get_size() == 1);
        REQUIRE(a.get_department() == 3);
        REQUIRE(a.get_duration() == 4);
        REQUIRE(a.get_specialization() == DailyBudget::Specialization::AMCS);
        REQUIRE(a.get_stipend() == 5);
        REQUIRE(a.get_number_students_with_stipend() == 6);

        DailyBudget b(a);
        REQUIRE(b.get_size() == 1);
        REQUIRE(b.get_department() == 3);
        REQUIRE(b.get_duration() == 4);
        REQUIRE(b.get_specialization() == DailyBudget::Specialization::AMCS);
        REQUIRE(b.get_stipend() == 5);
        REQUIRE(b.get_number_students_with_stipend() == 6);
    }
    SECTION("Setters")
    {
        DailyBudget a(10, 30, 40, DailyBudget::Specialization::AMCS, 50, 60);
        a.set_size(1);
        a.set_department(2);
        a.set_duration(3);
        a.set_specialization(DailyBudget::Specialization::IS);
        a.set_number_students_with_stipend(5);
        a.set_stipend(6);
        REQUIRE(a.get_size() == 1);
        REQUIRE(a.get_department() == 2);
        REQUIRE(a.get_duration() == 3);
        REQUIRE(a.get_specialization() == DailyBudget::Specialization::IS);
        REQUIRE(a.get_stipend() == 6);
        REQUIRE(a.get_number_students_with_stipend() == 5);
    }
}

TEST_CASE("EveningBudget")
{
    SECTION("Constructors")
    {
        EveningBudget a(1,2,3,EveningBudget::Contingent::ADULT_STUDENTS,EveningBudget::Qualification::POSTGRADUATE);
        REQUIRE(a.get_size() == 1);
        REQUIRE(a.get_department() == 2);
        REQUIRE(a.get_duration() == 3);
        REQUIRE(a.get_contingent() == EveningBudget::Contingent::ADULT_STUDENTS);
        REQUIRE(a.get_qual() == EveningBudget::Qualification::POSTGRADUATE);
    }
    SECTION("Setters")
    {
        EveningBudget a(1,2,3,EveningBudget::Contingent::ADULT_STUDENTS,EveningBudget::Qualification::POSTGRADUATE);
        a.set_size(10);
        a.set_department(20);
        a.set_duration(30);
        a.set_contingent(EveningBudget::Contingent::WORKING_STUDENTS);
        a.set_qualification(EveningBudget::Qualification::BACHELOR);
        REQUIRE(a.get_size() == 10);
        REQUIRE(a.get_department() == 20);
        REQUIRE(a.get_duration() == 30);
        REQUIRE(a.get_contingent() == EveningBudget::Contingent::WORKING_STUDENTS);
        REQUIRE(a.get_qual() == EveningBudget::Qualification::BACHELOR);
    }
}

TEST_CASE("Fee Paying")
{
    SECTION("Constructors")
    {
        FeePaying a(1,2,3,4,5);
        REQUIRE(a.get_size() == 1);
        REQUIRE(a.get_department() == 2);
        REQUIRE(a.get_duration() == 3);
        REQUIRE(a.get_num_contract() == 4);
        REQUIRE(a.get_fee() == 5);
    }

    SECTION("Setters")
    {
        FeePaying a(1,2,3,4,5);
        a.set_size(10);
        a.set_department(20);
        a.set_duration(30);
        a.set_num_contract(40);
        a.set_fee(50);
        REQUIRE(a.get_size() == 10);
        REQUIRE(a.get_department() == 20);
        REQUIRE(a.get_duration() == 30);
        REQUIRE(a.get_num_contract() == 40);
        REQUIRE(a.get_fee() == 50);
    }
}