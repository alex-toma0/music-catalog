//
// Created by alext on 11/10/2021.
//

#include "Melodie.h"
#include <iostream>

Melodie::Melodie(const std::string &nume, const int &lungime)
        : nume{nume}, lungime{lungime} {}

std::string Melodie::getNume() const{
    return nume;
}

int Melodie::getLungime() const{
    return lungime;
}


// operator <<
std::ostream &operator << (std::ostream &out, const Melodie &m) {
    out << "Nume: " << m.nume << ", Lungime: " << m.lungime / 60 << ":"
        << m.lungime % 60 << "\n";
    return out;
}