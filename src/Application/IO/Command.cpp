#include "Application/IO/Command.hpp"
#include "Application/Utils/Utils.hpp"
#include <string>
#include <vector>
#include <functional>
#include <iostream>


namespace Application
{
    Command::Command(std::string cmd, int argc, command_handler handler ) {
        this->cmd = std::move(cmd);
        this->argc = argc;
        this->handler = handler;
    };

    void Command::handle() {
        args_vec args;
        std::string buff;
        for ( int i = 0; i<this->argc; i++ ) {
            std::cin >> buff;
            args.push_back(buff);
        }
        (this->handler)(args);
    }

    bool Command::match(std::string cmd) {
        return Utils::strToLower(cmd) == Utils::strToLower(this->cmd);
    }

}
