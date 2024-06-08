#pragma once

#include <string>

namespace Application::Entity 
{
    class Osoba
    {
    private:
        int id;
        std::string imie;
        std::string nazwisko;

    public:
        Osoba(std::string imie, std::string nazwisko);
        void log();
        int getId();
        std::string getImie();
        std::string getNazwisko();
        bool operator < (const Osoba& other) const;
    };
}