#pragma once
#include "Application/IO/Command.hpp"


namespace Application
{
    class IO
    {
    private:
        std::vector<Command*> commands;

    public:
        IO();
        void setupCommandHandler();
        void handleNextCommand();
    };

    void displayMainMenu();
}
