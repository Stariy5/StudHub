#pragma once

#include "../istudhub/istudyinggroup.hpp"
class FeePaying : public IStudyingGroup
{
private:
    size_t size_;
    size_t num_department_;
    size_t duration_;
    size_t num_contract_;
    size_t semester_fee_;

public:
    FeePaying(size_t size, size_t num_department, size_t duration, size_t num_contract, size_t semester_fee);

    void show_info() override;

//    [[nodiscard]] IStudyingGroup get_form_education() const override;

    [[nodiscard]] size_t get_size() const override;

    void set_size(size_t size) override;

    [[nodiscard]] size_t get_department() const override;

    void set_department(size_t dep);

    void set_duration(size_t dur);

    [[nodiscard]] size_t get_duration() const;

    void set_num_contract(size_t contract);

    [[nodiscard]] size_t get_num_contract() const;

    [[nodiscard]] size_t get_fee() const;

    void set_fee(size_t fee);

    ~FeePaying() override = default;

};