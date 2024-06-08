#pragma once
#include "Application/IO/IO.hpp"

namespace Application
{
    class Main
    {
    private:
        IO *io;
        void displayMainMenu();

    public:
        Main();
        void start();
    };
}
