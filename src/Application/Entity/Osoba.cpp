#include "Application/Entity/Osoba.hpp"
#include "Application/Utils/Utils.hpp"
#include <iostream>

namespace Application::Entity 
{
    Osoba::Osoba(std::string imie, std::string nazwisko)  {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->id = Utils::generateUUID();
    }

    int Osoba::getId() {
        return this->id;
    }

    std::string Osoba::getImie() {
        return this->imie;
    };

    std::string Osoba::getNazwisko() {
        return this->nazwisko;
    };

    void Osoba::log() {
        std::cout << this->id << "\t" << this->imie << " " << this->nazwisko << std::endl;
    }

    bool Osoba::operator< (const Osoba& other) const {
        return (this->imie + " " + this->nazwisko) < (other.imie + " " + other.nazwisko);
    }
}