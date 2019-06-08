cmake_minimum_required(VERSION 3.13)
project(C_proj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)

include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})

add_definitions(${GTK2_CFLAGS_OTHER})
set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(C_proj
        ACCUEIL.c
        ACCUEIL.h
        Admin.c
        Admin.h
        constantes.h
        JEU.c
        JEU.h
        joueur.c
        joueur.h
        LOGIN.c
        LOGIN.h
        main.c
        MSGBOX.c
        MSGBOX.h
        QUESTION.c
        QUESTION.h
        Questions.c
        Questions.h
        Statistiques.c
        Statistiques.h)
target_link_libraries(C_proj ${GTK2_LIBRARIES})