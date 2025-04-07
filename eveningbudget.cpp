#include "eveningbudget.hpp"

EveningBudget::EveningBudget(size_t size, size_t num_department, size_t duration,
                             EveningBudget::Contingent contingent, EveningBudget::Qualification qualification) :
        size_(size),
        num_department_(num_department),
        duration_(duration),
        contingent_(contingent),
        qualification_(qualification)
{
}

void EveningBudget::show_info()
{
    std::cout << "The size of this group --> " << size_ << std::endl;
    std::cout << "The department number of this group --> " << num_department_ << std::endl;
    std::cout << "The duration of this group's studies --> " << duration_ << std::endl;
    if (contingent_ == EveningBudget::Contingent::ADULT_STUDENTS)
        std::cout << "In this group are studying --> Adult students" << std::endl;
    if (contingent_ == EveningBudget::Contingent::FAMILY_RESPONSIBILITIES)
        std::cout << "In this group are studying --> Students with family responsibilities" << std::endl;
    if (contingent_ == EveningBudget::Contingent::LIMITED_OPPORTUNITIES)
        std::cout << "In this group are studying --> Students with limited opportunities to complete daily education" << std::endl;
    if (contingent_ == EveningBudget::Contingent::WORKING_STUDENTS)
        std::cout << "In this group are studying --> Working students" << std::endl;
    if (qualification_ == EveningBudget::Qualification::BACHELOR)
        std::cout << "Qualification of this group --> Bachelor" << std::endl;
    if (qualification_ == EveningBudget::Qualification::MASTER)
        std::cout << "Qualification of this group --> Master" << std::endl;
    if (qualification_ == EveningBudget::Qualification::POSTGRADUATE)
        std::cout << "Qualification of this group --> Postgraduate" << std::endl;
    if (qualification_ == EveningBudget::Qualification::SPECIALIST)
        std::cout << "Qualification of this group --> Specialist" << std::endl;
}

size_t EveningBudget::get_size() const
{
    return size_;
}

void EveningBudget::set_size(size_t size)
{
    size_ = size;
}

size_t EveningBudget::get_department() const
{
    return num_department_;
}

void EveningBudget::set_department(size_t num_dep)
{
    num_department_ = num_dep;
}

void EveningBudget::set_duration(size_t dur)
{
    duration_ = dur;
}

void EveningBudget::set_contingent(EveningBudget::Contingent cont)
{
    contingent_ = cont;
}

void EveningBudget::set_qualification(EveningBudget::Qualification qual)
{
    qualification_ = qual;
}

size_t EveningBudget::get_duration() const
{
    return duration_;
}

EveningBudget::Contingent EveningBudget::get_contingent() const
{
    return contingent_;
}

EveningBudget::Qualification EveningBudget::get_qual() const
{
    return qualification_;
}

