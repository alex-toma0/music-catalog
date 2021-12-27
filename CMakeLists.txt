cmake_minimum_required(VERSION 3.5.1)
project(music_catalog)
set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -pedantic -g)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options(-stdlib=libstdc++)
    endif ()
endif()

add_executable(music_catalog main.cpp Melodie.cpp Melodie.h Album.h Album.cpp Artist.cpp Artist.h AlbumStudio.cpp AlbumStudio.h Compilatie.cpp Compilatie.h Exception.cpp Exception.h AlbumFactory.cpp AlbumFactory.h)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
target_link_libraries(music_catalog SDL2::Main SDL2::Mixer)






