//
// Created by alext on 11/23/2021.
//

#include "Album.h"
#include <iostream>
#include <vector>

std::string Album::getTitlu() const {
    return titlu;
}

int Album::getLungime() const {
    return lungime;
}

int Album::getAn() const {
    return an;
}

std::vector<Melodie>& Album::getMelodii() {
    return melodii;
}

// constructor init
Album::Album(const std::string &titlu,
             const int &an,
             const std::vector<Melodie> &melodii) : titlu{titlu}, an{an}, melodii{melodii} {
    lungime = 0;
    for(int i=0; i<getMelodii().size();i++) {
        lungime += melodii[i].getLungime();
    }
}

// operator <<
std::ostream &operator << (std::ostream &out, const Album &a) {
    out << "Titlu album: " << a.titlu  << ", Lungime: " << a.lungime / 3600 << ":"
        << a.lungime / 60 << ":" << a.lungime % 60
        << ", Nr. melodii: " << a.melodii.size() << "\nMelodii:\n";
    for(int i=0; i<a.melodii.size(); i++) {

        out << i+1 <<". " << a.melodii[i];
    }

    return out;
}