#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstddef>
#include <limits>
#include <exception>
#include <memory>
#include <typeinfo>

class IStudyingGroup
{
public:
    virtual void show_info() = 0;

    [[nodiscard]] virtual size_t get_size() const = 0;

    virtual void set_size(size_t size) = 0;

    [[nodiscard]] virtual size_t get_department() const = 0;

    virtual ~IStudyingGroup() = default;
};


