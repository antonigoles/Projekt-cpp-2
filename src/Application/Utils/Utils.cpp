#include <random>
#include <string>
#include <iostream>

namespace Application::Utils
{
    /**
     * nienajladniejsze rozwiazanie, ale dobre dostatecznie
    */
    int lastuuid=0;
    /*
     * Funkcja do generowania unikatowych indentyfikatorow
    */
    int generateUUID() {
        return lastuuid++;
    }

    std::string strToLower(std::string &str) {
        std::string buff = "";
        for ( int i = 0; i<str.size(); i++ ) {
            buff += tolower(str[i]);
        }
        return std::move(buff);
    }
}