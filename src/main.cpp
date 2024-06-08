#include "Application/Application.hpp"

int main()
{
    /*
     * Przenosimy logike aplikacji z poza pliku Main zeby nie bylo zbyt gesto
    */
    Application::Main *app = new Application::Main();
    app->start();
}