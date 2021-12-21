//
// Created by alex on 20.12.2021.
//

#ifndef MUSIC_CATALOG_EXCEPTION_H
#define MUSIC_CATALOG_EXCEPTION_H
#include <iostream>

class Exception : public std::exception {
protected:
    std::string mesaj;
public:
    Exception(const std::string& mesaj);
    virtual const char* what() const noexcept override;
};


#endif //MUSIC_CATALOG_EXCEPTION_H
