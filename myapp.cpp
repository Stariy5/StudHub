#include "myapp.hpp"


bool try_input_size_t(size_t &dst)
{
    std::cin >> dst;
    if (std::cin.good())
        return true;
    if (std::cin.eof())
        throw std::runtime_error("EOF");
    if (std::cin.bad())
        throw std::runtime_error("Broken input");
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

size_t input_size_t()
{
    size_t res = 0;
    while (!try_input_size_t(res));
    return res;
}

void print_command(const std::string &command)
{
    std::cout << command << std::endl;
}

size_t get_command()
{
    size_t command{};
    std::cout << "Make your choice --> " << std::endl;
    command = input_size_t();
    return command;
}

void dialog_for_change_group()
{
    std::cout << "What do you want to change?" << std::endl;

    std::vector <std::string> parameters_group = {"1. Size of student in the group", "2. Amount of stipend",
                                                  "3. Number of students, who can gets stipend", "4. Semester fee",
                                                  "5. That`s all"};
    std::for_each(parameters_group.begin(), parameters_group.end(), print_command);
}

void show_all_specialization()
{
    std::cout << "Specializations:" << std::endl;

    std::vector <std::string> specializations = {"1. Automated Control Systems",
                                                 "2. Applied Mathematics and Computer Science",
                                                 "3. Information Security", "4. Software Engineering",
                                                 "5. Computer Science and Computing Technology"};
    std::for_each(specializations.begin(), specializations.end(), print_command);

}

void show_all_contingents()
{
    std::cout << "Contingents:" << std::endl;

    std::vector <std::string> contingents = {"1. Working students", "2. Adult students",
                                             "3. Family responsibilities", "4. Limited opportunities"};
    std::for_each(contingents.begin(), contingents.end(), print_command);

}

void show_all_qualifications()
{
    std::cout << "qualifications:" << std::endl;

    std::vector <std::string> qualifications = {"1. Bachelor", "2. Specialist", "3. Master", "4. Postgraduate"};
    std::for_each(qualifications.begin(), qualifications.end(), print_command);

}

void show_all_groups()
{
    std::cout << "groups:" << std::endl;

    std::vector <std::string> groups = {"1. Daily budget", "2. Evening budget", "3. Fee paying"};
    std::for_each(groups.begin(), groups.end(), print_command);

}

void all_commands()
{
    std::cout << "Menu:" << std::endl;

    std::vector <std::string> commands = {"1. Create new group", "2. Change group`s characteristics",
                                                  "3. Exclude descriptor of this group",
                                                  "4. Show all groups of the specified department",
                                                  "5. Calculate total income from all groups", "6. Exit"};
    std::for_each(commands.begin(), commands.end(), print_command);

}

// MAIN DIALOG
void process_command(Table<size_t, std::shared_ptr<IStudyingGroup>> &table, StudHub app, const size_t &command)
{
    switch (command)
    {
        case 1:
        {
            std::cout << "Which group do you want to create?" << std::endl;
            show_all_groups();
            int gr = get_command();

            std::shared_ptr<DailyBudget> dbgroup = std::make_shared<DailyBudget>(0, 0, 0, DailyBudget::Specialization::CSCT, 0, 0);
            std::shared_ptr<EveningBudget> ebgroup = std::make_shared<EveningBudget>(0, 0, 0,EveningBudget::Contingent::WORKING_STUDENTS, EveningBudget::Qualification::SPECIALIST);
            std::shared_ptr<FeePaying> fpgroup = std::make_shared<FeePaying>(0, 0, 0, 0, 0);

            if(gr == 1)
            {
                StudHub::index_t index = app.create_new_group(dbgroup, gr);
                table.push_back(index, dbgroup);
            }
            if(gr == 2)
            {
                StudHub::index_t index = app.create_new_group(ebgroup, gr);
                table.push_back(index, ebgroup);
            }
            if(gr == 3)
            {
                StudHub::index_t index = app.create_new_group(fpgroup, gr);
                table.push_back(index, fpgroup);
            }
            break;
        }

        case 2:
        {
            std::cout << "Which group do you want to change, enter its index --> " << std::endl;
            auto group_it = table.find_elem(input_size_t());
            if(group_it != table.end())
            {
                app.change_group_info(*group_it);
            }
            else
            {
                std::cout << "This group doesn`t exist" << std::endl;
            }
            break;
        }

        case 3:
        {
            std::cout << "Which group do you want to remove, enter its index --> " << std::endl;
            app.delete_group(table, input_size_t());
            break;
        }

        case 4:
        {
            std::cout << "Which department's groups do you want to see, enter this department -->" << std::endl;
            app.show_all_department_group(table, input_size_t());
            break;
        }

        case 5:
        {
            size_t total_income = app.get_total_income(table);
            std::cout << "The total income from all groups is " << total_income << std::endl;
            break;
        }

        default:
        {
            break;
        }

    }
}

//----------------------------------------------------------------------------------------------

StudHub::index_t StudHub::create_new_group(std::shared_ptr<IStudyingGroup> new_group, size_t gr)
{
    index_t index = 0;
    if(gr == 1) index = create_new_dbgroup(new_group);
    else if(gr == 2) index = create_new_ebgroup(new_group);
    else if(gr == 3) index = create_new_fpgroup(new_group);

    return index;
}

void StudHub::process_changing(size_t command, std::shared_ptr<IStudyingGroup> group)
{
    switch (command)
    {
        case 1:
        {
            std::cout << "Enter new size of this group" << std::endl;
            size_t size = input_size_t();
            group->set_size(size);
            break;
        }

        case 2:
        {
            if (!std::dynamic_pointer_cast<DailyBudget>(group))
            {
                throw std::logic_error("This group doesn`t receive a stipend");
            }

//            std::shared_ptr<DailyBudget> dbgroup = std::dynamic_pointer_cast<DailyBudget>(group);

            if (std::shared_ptr<DailyBudget> dbgroup = std::dynamic_pointer_cast<DailyBudget>(group))
            {
                std::cout << "Enter new size of stipend for this group" << std::endl;
                size_t new_stipend = input_size_t();
                dbgroup->set_stipend(new_stipend);
            }
            break;
        }

        case 3:
        {
            if (!std::dynamic_pointer_cast<DailyBudget>(group))
            {
                throw std::logic_error("This group doesn`t receive a stipend");
            }

            std::shared_ptr<DailyBudget> dbgroup = std::dynamic_pointer_cast<DailyBudget>(group);
//            std::shared_ptr<DailyBudget> dbgroup = std::make_shared<DailyBudget>(group);

            if (dbgroup)
            {
                std::cout << "Enter new number of students who can get stipend" << std::endl;
                size_t new_number_of_students = input_size_t();
                dbgroup->set_number_students_with_stipend(new_number_of_students);
            }
            break;
        }

        case 4:
        {
            if (strcmp(typeid(group).name(), "FeePaying") != 0)
            {
                throw std::logic_error("This group doesn`t pay fee for education");
            }

            std::shared_ptr<FeePaying> fpgroup = std::dynamic_pointer_cast<FeePaying>(group);

            if (fpgroup)
            {
                std::cout << "Enter new size of semester fee for this group" << std::endl;
                size_t new_size_of_fee = input_size_t();
                fpgroup->set_fee(new_size_of_fee);
            }
            break;
        }

        default:
        {
            break;
        }
    }
}

void StudHub::change_group_info(std::shared_ptr<IStudyingGroup> group)
{
    while (true)
    {
        dialog_for_change_group();
        size_t command = get_command();
        if (command == 5)
        {
            break;
        }
        process_changing(command, group);
    }
}

StudHub::index_t StudHub::create_new_dbgroup(std::shared_ptr<IStudyingGroup> group)
{
    std::shared_ptr<DailyBudget> dbgroup = std::dynamic_pointer_cast<DailyBudget>(group);

    std::cout << "Enter size of this group" << std::endl;
    dbgroup->set_size(input_size_t());

    std::cout << "Enter number of department for this group" << std::endl;
    dbgroup->set_department(input_size_t());

    std::cout << "Enter duration of their education" << std::endl;
    dbgroup->set_duration(input_size_t());

    std::cout << "Enter specialization of this group" << std::endl;
    show_all_specialization();
    int specialization_int = get_command();
    DailyBudget::Specialization specialization = static_cast<DailyBudget::Specialization>(specialization_int);
    dbgroup->set_specialization(specialization);

    std::cout << "Enter size of stipend for this group" << std::endl;
    dbgroup->set_stipend(input_size_t());

    std::cout << "Enter number of student who can get stipend" << std::endl;
    dbgroup->set_number_students_with_stipend(input_size_t());

    std::cout << "Finally enter index for this group" << std::endl;
    index_t index = input_size_t();
    return index;
}

StudHub::index_t StudHub::create_new_ebgroup(std::shared_ptr<IStudyingGroup> group)
{
    std::shared_ptr<EveningBudget> ebgroup = std::dynamic_pointer_cast<EveningBudget>(group);

    std::cout << "Enter size of this group" << std::endl;
    ebgroup->set_size(input_size_t());

    std::cout << "Enter number of department for this group" << std::endl;
    ebgroup->set_department(input_size_t());

    std::cout << "Enter duration of their education" << std::endl;
    ebgroup->set_duration(input_size_t());

    std::cout << "Enter contingent of students" << std::endl;
    show_all_contingents();
    int cont_int = get_command();
    EveningBudget::Contingent contingent = static_cast<EveningBudget::Contingent>(cont_int);
    ebgroup->set_contingent(contingent);

    std::cout << "Enter qualification of this group" << std::endl;
    show_all_qualifications();
    int qual_int = get_command();
    EveningBudget::Qualification qualification = static_cast<EveningBudget::Qualification>(qual_int);
    ebgroup->set_qualification(qualification);

    std::cout << "Finally enter index for this group" << std::endl;
    index_t index = input_size_t();
    return index;
}

StudHub::index_t StudHub::create_new_fpgroup(std::shared_ptr<IStudyingGroup> group)
{
    std::shared_ptr<FeePaying> fpgroup = std::dynamic_pointer_cast<FeePaying>(group);

    std::cout << "Enter size of this group" << std::endl;
    fpgroup->set_size(input_size_t());

    std::cout << "Enter number of department for this group" << std::endl;
    fpgroup->set_department(input_size_t());

    std::cout << "Enter duration of their education" << std::endl;
    fpgroup->set_duration(input_size_t());

    std::cout << "Enter number of contract of this group" << std::endl;
    fpgroup->set_num_contract(input_size_t());

    std::cout << "Enter semester fee for this group" << std::endl;
    fpgroup->set_fee(input_size_t());

    std::cout << "Finally enter index for this group" << std::endl;
    index_t index = input_size_t();
    return index;
}

void StudHub::delete_group(Table<size_t, std::shared_ptr<IStudyingGroup>> &table, index_t index)
{
    table.remove_elem(index);
}

void StudHub::show_all_department_group(Table<size_t, std::shared_ptr<IStudyingGroup>> &table, size_t department)
{
    for(size_t i = 0; i < table.get_size(); ++i)
    {
        if(table[i]->get_department() == department)
        {
            std::cout << "Group #" << i << " has following characteristics:" << std::endl;
            table[i]->show_info();
        }
    }
}

std::mutex fee_mutex;
size_t total_fee = 0;

/// многопоточная функция суммарной платы студентов
size_t StudHub::get_total_income(const Table<size_t, std::shared_ptr<IStudyingGroup>> &table)
{
    size_t num_threads = std::thread::hardware_concurrency();
    if(num_threads == 0)
        {
            num_threads = 1;
        }
    std::vector<std::thread> threads;
    size_t group_size = table.get_size();
    size_t chunk = 0;
    size_t result = 0;
    if(group_size >= num_threads)
    {
        chunk = group_size / num_threads;
    }
    else
    {
        num_threads = group_size;
        chunk = 1;
    }
    for(size_t i = 0; i < num_threads; ++i)
    {
        size_t start_index = i * chunk;
        size_t end_index = (i == num_threads - 1)? group_size : start_index + chunk;
        threads.emplace_back(sum_fees_for_groups, std::vector<std::shared_ptr<IStudyingGroup>>(table.begin() + start_index, table.begin() + end_index));
    }
    for(auto &thread : threads)
    {
        thread.join();
    }
    result = total_fee;
    total_fee = 0;
    return result;
}

void StudHub::sum_fees_for_groups(const std::vector<std::shared_ptr<IStudyingGroup>> &groups)
{
    size_t local_fee = 0;
    for(const auto &group:groups)
    {
        if(auto fee_group = std::dynamic_pointer_cast<FeePaying>(group))
        {
            local_fee += fee_group->get_fee();
        }
    }
    std::lock_guard<std::mutex> lock(fee_mutex);
    total_fee += local_fee;
}



