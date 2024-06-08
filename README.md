# Projekt 2 na Programowanie 1 (C++)

Antoni Goles

## 1. Wymagania

- Kompilator C++ wspierający C++20 (większość powinna działać, ale testowany był na Apple clang 15.0.0)
- Make (Testowane na wersji 3.81)
- Systemy: Windos, MacOS (ARM), Linux - (Testowane pod MacOS w wersji ARM)

## 2. Kompilowanie i uruchamianie

```
# Kompilacja
make

# Uruchamianie
make run
```

## 3. Wyjaśnienie kodu

- Punkt wejściowy w pliku `main.cpp` w funkcji `main()` tworzymy
  obiekt `Application::Main()`, który jest głównym obiektem zajmującym się naszą aplikacją.

- W Obiekcie `Application::Main()` inicjujemy kolejny obiekt `Application::IO()`,
  który zajmuje się komunikacją uzytkownika z aplikacją, oraz "Input Loop" czyli
  nieskończona pętla, która wykonuje cykl: <br>
  `oczekuj na wejscie od uzytkownika -> wykonaj komende -> wróc do oczekiwania na komende`

- Klasa `Application::IO()`, która zajmuje się wejściem/wyjściem deklaruje wewnątrz
  wszelakie zachowanie wszystkich komend przechowując je jako obiekty `Application::Command()`

- W pojedyńczych "handlerach" komend wykonujemy rózne procedoru serwisu `Application::Service::Lista()`
  który wyciągamy z globalnego repozytorium serwisów `Application::Service::Repository`

- `Application::Service::Lista()` to serwis (Nasza klasa Lista z zadania), który zajmuje się
  zarządzaniem naszymi "Osobami", czyli obiektami klasy `Application::Entity::Osoba()`

- `Application::Entity::Osoba()` to klasa reprezentująca "Osobe", zawiera pola: ID, Imie i Nazwisko

## 4. Komendy programu

```
DODAJ <imie> <nazwisko> - Dodaj uzytkownika z <Imie> i <Nazwisko>
USUN <id> - Usun uzytkownika z id: <id>
WSZYSTKO - Pokaz liste wszystkich uztykownikow
POKAZ <id> - Pokaz uzytkownika z id: <id>
MENU - Pokaz menu
WYJDZ - Wyjdz z programu
CLEAR - Wyczysc ekran
```
