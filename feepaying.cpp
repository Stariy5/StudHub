#include "feepaying.hpp"

FeePaying::FeePaying(size_t size, size_t num_department, size_t duration, size_t num_contract, size_t semester_fee)
        :
        size_(size),
        num_department_(num_department),
        duration_(duration),
        num_contract_(num_contract),
        semester_fee_(semester_fee)
{
}

void FeePaying::show_info()
{
    std::cout << "The size of this group --> " << size_ << std::endl;
    std::cout << "The department number of this group --> " << num_department_ << std::endl;
    std::cout << "The duration of this group's studies --> " << duration_ << std::endl;
    std::cout << "The number of contract for this group --> " << num_contract_ << std::endl;
    std::cout << "The semester fee for each student from this group --> " << semester_fee_ << std::endl;
}

size_t FeePaying::get_size() const
{
    return size_;
}

void FeePaying::set_size(size_t size)
{
    size_ = size;
}

size_t FeePaying::get_department() const
{
    return num_department_;
}

size_t FeePaying::get_fee() const
{
    return semester_fee_;
}

void FeePaying::set_fee(size_t fee)
{
    semester_fee_ = fee;
}

void FeePaying::set_department(size_t dep)
{
    num_department_ = dep;
}

void FeePaying::set_duration(size_t dur)
{
    duration_ = dur;
}

void FeePaying::set_num_contract(size_t contract)
{
    num_contract_ = contract;
}

size_t FeePaying::get_duration() const
{
    return duration_;
}

size_t FeePaying::get_num_contract() const
{
    return num_contract_;
}

