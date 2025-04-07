#include "../istudhub/istudyinggroup.hpp"
#include "../myapp/myapp.hpp"
#include "../dailybudget/dailybudget.cpp"
#include "../eveningbudget/eveningbudget.cpp"
#include "../feepaying/feepaying.cpp"

int main()
{
    Table<size_t, std::shared_ptr<IStudyingGroup>> tbl;
    StudHub app;
    try
    {
        while (true)
        {
            all_commands();
            int command = get_command();
            if (command == 6)
            {
                break;
            }
            process_command(tbl, app, command);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}