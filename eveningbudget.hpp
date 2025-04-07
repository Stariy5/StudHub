#pragma once

#include "../istudhub/istudyinggroup.hpp"
//#include "../myapp/myapp.cpp"

class EveningBudget : public IStudyingGroup
{
public:
    enum class Contingent
    {
        WORKING_STUDENTS,
        ADULT_STUDENTS,
        FAMILY_RESPONSIBILITIES,
        LIMITED_OPPORTUNITIES
    };

    enum class Qualification
    {
        BACHELOR,
        SPECIALIST,
        MASTER,
        POSTGRADUATE
    };

private:
    size_t size_;
    size_t num_department_;
    size_t duration_;
    Contingent contingent_;
    Qualification qualification_;

public:
    EveningBudget(size_t size, size_t num_department, size_t duration, Contingent contingent,
                  Qualification qualification);

    void show_info() override;

//    [[nodiscard]] IStudyingGroup get_form_education() const override;

    [[nodiscard]] size_t get_size() const override;

    void set_size(size_t size) override;

    [[nodiscard]] size_t get_department() const override;

    void set_department(size_t num_dep);

    void set_duration(size_t dur);

    [[nodiscard]] size_t get_duration() const;

    void set_contingent(EveningBudget::Contingent cont);

    [[nodiscard]] Contingent get_contingent() const;

    void set_qualification(EveningBudget::Qualification qual);

    [[nodiscard]] Qualification get_qual() const;

    ~EveningBudget() override = default;

//    friend StudHub;
};