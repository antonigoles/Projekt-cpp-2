#include <iostream>
#include "Application/Entity/Osoba.hpp"
#include "Application/IO/Command.hpp"
#include "Application/IO/IO.hpp"
#include "Application/Service/ServiceRepository.hpp"

namespace Application
{
    using namespace Entity;

    IO::IO() {};

    void handleDodaj(args_vec args) {
        Osoba osoba = Osoba(args[0], args[1]);
        std::cout << "Dodano jako" << std::endl;
        osoba.log();
        Service::Repository::listaService.insert(osoba);
    };

    void handleUsun(args_vec args) {
        try {
            int id = stoi(args[0]);
            Service::Repository::listaService.remove(id);
            std::cout << "Usunieto uzytkownika z id: " << id << std::endl;
        } catch (std::invalid_argument &exception) {
            std::cout << "Niepoprawne ID" << std::endl;
        } catch(std::string message) {
            std::cout << message << std::endl;
        }
    };

    void handleWszystko(args_vec args) {
        Service::Repository::listaService.logAll();
    };

    void handlePokaz(args_vec args) {
        try {
            int id = stoi(args[0]);
            auto found = Service::Repository::listaService.find(id);
            found.log();
        } catch(std::invalid_argument &exception) {
            std::cout << "Niepoprawne ID" << std::endl;
        }  catch(std::string message) {
            std::cout << message << std::endl;
        }
    };

    void handleMenu(args_vec args) {
        displayMainMenu();
    };

    void handleWyjdz(args_vec args) {
        exit(0);
    };

    void handleClear(args_vec args) {
        system("clear");
    };

    void IO::setupCommandHandler() {
        this->commands = {
            new Command("DODAJ", 2, &handleDodaj),
            new Command("USUN", 1, &handleUsun),
            new Command("POKAZ", 1, &handlePokaz),
            new Command("WSZYSTKO", 0, &handleWszystko),
            new Command("MENU", 0, &handleMenu),
            new Command("WYJDZ", 0, &handleWyjdz),
            new Command("CLEAR", 0, &handleClear)
        };
    };

    void IO::handleNextCommand() {
        std::cout << "> ";
        std::string inp;
        std::cin >> inp;
        for ( auto cmd : this->commands ) {
            if ( cmd->match(inp) ) {
                cmd->handle();
                return;
            }
        }
        std::cout << "Nierozpoznana komenda!" << std::endl;
    };

    void displayMainMenu() {
        std::cout << " MENU KOMEND" << std::endl << std::endl;
        std::cout << " DODAJ <imie> <nazwisko> - Dodaj uzytkownika z <Imie> i <Nazwisko>" << std::endl;
        std::cout << " USUN <id> - Usun uzytkownika z id: <id>" << std::endl;
        std::cout << " WSZYSTKO - Pokaz liste wszystkich uztykownikow" << std::endl;
        std::cout << " POKAZ <id> - Pokaz uzytkownika z id: <id>" << std::endl;
        std::cout << " MENU - Pokaz menu" << std::endl;
        std::cout << " WYJDZ - Wyjdz z programu" << std::endl;
        std::cout << " CLEAR - Wyczysc ekran" << std::endl;
        std::cout << std::endl;
    }
};
