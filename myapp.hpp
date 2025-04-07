#pragma once
#include "../dailybudget/dailybudget.hpp"
#include "../eveningbudget/eveningbudget.hpp"
#include "../feepaying/feepaying.hpp"
#include "../table/table.hpp"
#include <thread>
#include <mutex>

class StudHub
{
private:
    void process_changing(size_t command, std::shared_ptr<IStudyingGroup> group);

public:
    using index_t = size_t;
    index_t create_new_group(std::shared_ptr<IStudyingGroup> new_group, size_t gr);

    index_t create_new_dbgroup(std::shared_ptr<IStudyingGroup> group);

    index_t create_new_ebgroup(std::shared_ptr<IStudyingGroup> group);

    index_t create_new_fpgroup(std::shared_ptr<IStudyingGroup> new_group);

    void change_group_info(std::shared_ptr<IStudyingGroup> group);

    void delete_group(Table<size_t, std::shared_ptr<IStudyingGroup>> &table, index_t index);

    void show_all_department_group(Table<size_t, std::shared_ptr<IStudyingGroup>> &table, size_t department);

    size_t get_total_income(const Table<size_t, std::shared_ptr<IStudyingGroup>> & table);

    static void sum_fees_for_groups(const std::vector<std::shared_ptr<IStudyingGroup>> & groups);
};

bool try_input_size_t(size_t &dst);
size_t input_size_t();
void print_command(const std::string &command);
size_t get_command();
void dialog_for_change_group();
void show_all_specialization();
void show_all_contingents();
void show_all_qualifications();
void show_all_groups();
void all_commands();
void process_command(Table<size_t, std::shared_ptr<IStudyingGroup>> &table, StudHub app, const size_t &command);