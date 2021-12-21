//
// Created by alex on 20.12.2021.
//

#include "Exception.h"
Exception::Exception(const std::string& mesaj) : mesaj{mesaj} {}

const char *Exception::what() const noexcept {
    return mesaj.c_str();
}