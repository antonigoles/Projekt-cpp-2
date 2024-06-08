#include "Application/Application.hpp"
#include "Application/IO/Command.hpp"
#include "Application/IO/IO.hpp"
#include <iostream>


namespace Application
{
    Main::Main() {
        this->io = new IO();
    }

    void Main::start() 
    {
        system("clear");
        this->io->setupCommandHandler();
        Application::displayMainMenu();
        while (true) {
            this->io->handleNextCommand();
        }
    };
};
