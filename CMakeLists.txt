cmake_minimum_required(VERSION 3.5.1)
project(music_catalog)
set(CMAKE_CXX_STANDARD 14)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
        option(GIT_SUBMODULE "Check submodules during build" ON)
        if(GIT_SUBMODULE)
                message(STATUS "Submodule update")
                execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                                RESULT_VARIABLE GIT_SUBMOD_RESULT)
                if(NOT GIT_SUBMOD_RESULT EQUAL "0")
                        message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}")
                endif()
        endif()
endif()

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_mixer)
add_executable(music_catalog main.cpp Melodie.cpp Melodie.h Album.h Album.cpp Artist.cpp Artist.h AlbumStudio.cpp AlbumStudio.h Compilatie.cpp Compilatie.h Exception.cpp Exception.h AlbumFactory.cpp AlbumFactory.h GlobalShuffle.cpp GlobalShuffle.h)
#if (MSVC)
    #add_compile_options(/W4)
#else ()
    #add_compile_options(-Wall -Wextra -pedantic -g)
    #if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        #add_compile_options(-stdlib=libstdc++)
    #endif ()
#endif()

target_include_directories(${PROJECT_NAME}
        PUBLIC external/SDL/include
        PUBLIC external/SDL_mixer/include
        )

target_link_libraries(music_catalog SDL2 SDL2main SDL2_mixer)






