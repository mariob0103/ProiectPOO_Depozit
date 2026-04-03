cmake_minimum_required(VERSION 3.20)
project(Proiect_Depozit_POO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(proiect_POO
        main.cpp
        Persoana.cpp
        Angajat.cpp
        Picker.cpp
        Gestionar.cpp
        Manipulant.cpp
        Client.cpp
        ClientUE.cpp
        ClientNonUE.cpp
        Produs.cpp
        ProdusFood.cpp
        ProdusNonFood.cpp
        ProdusPerisabil.cpp
        ProdusFragil.cpp
        Depozit.cpp
)

target_include_directories(proiect_POO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})