#include "dailybudget.hpp"

DailyBudget::DailyBudget(size_t size, size_t num_department, size_t duration,
                         Specialization specialization, size_t size_of_stipend,
                         size_t num_student_with_stipend) :
        size_(size),
        num_department_(num_department),
        duration_(duration),
        specialization_(specialization),
        size_of_stipend_(size_of_stipend),
        num_student_with_stipend_(num_student_with_stipend)
{
}

DailyBudget::DailyBudget(const DailyBudget &other) :
        size_(other.size_),
        num_department_(other.num_department_),
        duration_(other.duration_),
        specialization_(other.specialization_),
        size_of_stipend_(other.size_of_stipend_),
        num_student_with_stipend_(other.num_student_with_stipend_)
{

}

void DailyBudget::show_info()
{
    std::cout << "The size of this group --> " << size_ << std::endl;
    std::cout << "The department number of this group --> " << num_department_ << std::endl;
    std::cout << "The duration of this group's studies --> " << duration_ << std::endl;
    if (specialization_ == DailyBudget::Specialization::ACS)
        std::cout << "The specialization of this group --> Automated Control Systems" << std::endl;
    if (specialization_ == DailyBudget::Specialization::AMCS)
        std::cout << "The specialization of this group --> Applied Mathematics and Computer Science" << std::endl;
    if (specialization_ == DailyBudget::Specialization::IS)
        std::cout << "The specialization of this group --> Information Security" << std::endl;
    if (specialization_ == DailyBudget::Specialization::SE)
        std::cout << "The specialization of this group --> Software Engineering" << std::endl;
    if (specialization_ == DailyBudget::Specialization::CSCT)
        std::cout << "The specialization of this group --> Computer Science and Computing Technology" << std::endl;
    std::cout << "The size of stipend of this group --> " << size_of_stipend_ << std::endl;
    std::cout << "The number student with stipend of this group --> " << num_student_with_stipend_ << std::endl;
}

size_t DailyBudget::get_size() const
{
    return size_;
}

void DailyBudget::set_size(size_t size)
{
    size_ = size;
}

size_t DailyBudget::get_department() const
{
    return num_department_;
}

size_t DailyBudget::get_stipend() const
{
    return size_of_stipend_;
}

void DailyBudget::set_stipend(size_t stipend)
{
    size_of_stipend_ = stipend;
}

DailyBudget::Specialization DailyBudget::get_specialization() const
{
    return specialization_;
}

void DailyBudget::set_number_students_with_stipend(size_t num)
{
    num_student_with_stipend_ = num;
}

void DailyBudget::set_department(size_t num_dep)
{
    num_department_ = num_dep;
}

void DailyBudget::set_duration(size_t dur)
{
    duration_ = dur;
}

void DailyBudget::set_specialization(DailyBudget::Specialization specialization)
{
    specialization_ = specialization;
}

size_t DailyBudget::get_duration() const
{
    return this->duration_;
}

size_t DailyBudget::get_number_students_with_stipend() const
{
    return this->num_student_with_stipend_;
}