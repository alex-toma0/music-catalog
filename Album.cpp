//
// Created by alext on 11/23/2021.
//

#include "Album.h"
#include <iostream>
#include <vector>

std::string Album::getTitlu() const {
    return titlu;
}

const std::vector<Melodie> &Album::getMelodii() const {
    return melodii;
}

int Album::getLungime() const {
    return lungime;
}

int Album::getAn() const {
    return an;
}

//constr de baza
Album::Album() {}

// destructor
Album::~Album() {}
// constructor init
Album::Album(const std::string &titlu,
             const int &an,
             const std::vector<Melodie> &melodii) : titlu{titlu}, an{an}, melodii{melodii} {
    lungime = 0;
    for (size_t i = 0; i < getMelodii().size(); i++) {
        lungime += melodii[i].getLungime();
    }
}

// functia virtuala printAlbum se va ocupa de afisare
std::ostream &operator<<(std::ostream &out, const Album &a) {
    return a.printAlbum(out);

}

