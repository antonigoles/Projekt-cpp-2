#include "Application/Service/Lista.hpp"
#include "Application/Entity/Osoba.hpp"
#include <iostream>

namespace Application::Service
{
    using namespace Entity; 

    void Lista::insert(Osoba osoba) {
        this->osoby.push_back(osoba);
        std::sort(this->osoby.begin(), this->osoby.end());
    };

    void Lista::remove(int id) {
        for ( int i = 0; i<osoby.size(); i++ ) {
            Osoba osoba = osoby[i];
            if ( osoba.getId() == id ) {
                this->osoby.erase(osoby.begin() + i);
                return;
            }
        }
        throw (std::string)("Nie ma osoby z ID: ") + std::to_string(id);
    };

    Osoba Lista::find(int id) {
        for ( auto osoba : this->osoby ) {
            if ( osoba.getId() == id ) {
                return osoba;
            }
        }
        throw (std::string)("Nie ma osoby z ID: ") + std::to_string(id);
    };

    void Lista::logAll() {
        std::cout << std::endl << "Lista osob" << std::endl;
        for ( auto osoba : this->osoby ) {
            osoba.log();
        }
    };
}