#pragma once

#include <string>
#include <vector>
#include <functional>

namespace Application
{;
    typedef std::vector<std::string> args_vec;
    typedef std::function<void(args_vec)> command_handler;
    class Command
    {
    private:
        command_handler handler;
        std::string cmd;
        int argc;
    public:
        Command(std::string cmd, int argc, command_handler handler);
        void handle();
        bool match(std::string cmd);
    };
}
