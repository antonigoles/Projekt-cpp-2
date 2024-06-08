#pragma once
#include <random>
#include <string>

namespace Application::Utils
{
    /*
     * Funkcja do generowania unikatowych indentyfikatorow
    */
    int generateUUID();

    std::string strToLower(std::string &str);
}