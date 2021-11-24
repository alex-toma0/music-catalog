//
// Created by alext on 11/23/2021.
//
#ifndef TEMA1_ALBUM_H
#define TEMA1_ALBUM_H
#include <iostream>
#include <vector>
#include "Melodie.h"

class Album {
private:
    std::string titlu;
    int lungime, an;
    std::vector<Melodie> melodii;

public:
    Album(const std::string &titlu,
          const int &an,
          const std::vector<Melodie> &melodii);

    std::string getTitlu() const;
    int getLungime() const;
    int getNr() const;
    int getAn() const;
    std::vector<Melodie>& getMelodii();

    // operator <<
    friend std::ostream &operator << (std::ostream &out, const Album &a);

};
#endif //TEMA1_ALBUM_H
