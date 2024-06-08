#pragma once
#include <Application/Entity/Osoba.hpp>
#include <vector>

namespace Application::Service
{
    class Lista
    {
    private:
        std::vector<Entity::Osoba> osoby;

    public:
        void insert(Entity::Osoba osoba);
        void remove(int id);
        Entity::Osoba find(int id);
        void logAll();
    };
}