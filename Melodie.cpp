//
// Created by alext on 11/10/2021.
//

#include "Melodie.h"
#include <iostream>

Melodie::Melodie(const std::string &nume, const int &lungime, const std::string &album, const int &pozitie)
        : nume{nume}, lungime{lungime}, album{album}, pozitie{pozitie} {}

std::string Melodie::getNume() const{
    return nume;
}

int Melodie::getLungime() const{
    return lungime;
}

std::string Melodie::getAlbum() const{
    return album;
}

int Melodie::getPozitie() const{
    return pozitie;
}

// operator <<
std::ostream &operator << (std::ostream &out, const Melodie &m) {
    out << "Nume: " << m.nume << ", Lungime: " << m.lungime / 60 << ":"
        << m.lungime % 60 << ", Album: "<< m.album << ", Pozitia pe album: "
        << m.pozitie << "\n";
    return out;
}

