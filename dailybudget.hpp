#pragma once
#include "../istudhub/istudyinggroup.hpp"


class DailyBudget : public IStudyingGroup
{
public:
    enum class Specialization
    {
        AMCS,
        IS,
        SE,
        ACS,
        CSCT
    };

private:
    size_t size_;
    size_t num_department_;
    size_t duration_;
    Specialization specialization_;
    size_t size_of_stipend_;
    size_t num_student_with_stipend_;

public:
    DailyBudget(size_t size, size_t num_department, size_t duration,
                Specialization specialization, size_t size_of_stipend, size_t num_student_with_stipend);

    DailyBudget(const DailyBudget &other);

    void show_info() override;

//    [[nodiscard]] IStudyingGroup get_form_education() const override;

    [[nodiscard]] size_t get_size() const override;

    void set_size(size_t size) override;

    [[nodiscard]] size_t get_department() const override;

    void set_department(size_t num_dep);

    void set_duration(size_t dur);

    [[nodiscard]] size_t get_duration() const;

    [[nodiscard]] size_t get_stipend() const;

    void set_stipend(size_t stipend);

    void set_number_students_with_stipend(size_t num);

    [[nodiscard]] size_t get_number_students_with_stipend() const;


    [[nodiscard]] Specialization get_specialization() const;

    void set_specialization(DailyBudget::Specialization specialization);

    ~DailyBudget() override = default;

};