//
// Created by alext on 11/10/2021.
//

#ifndef TEMA1_MELODIE_H
#define TEMA1_MELODIE_H
#include <iostream>

class Melodie{
private:
    std::string nume, album;
    int lungime, pozitie;
public:
    Melodie(const std::string &nume, const int &lungime, const std::string &album, const int &pozitie);
    std::string getNume() const;
    int getLungime() const;
    std::string getAlbum() const;
    int getPozitie() const;

    // operator <<
    friend std::ostream &operator << (std::ostream &out, const Melodie &m);
};

#endif //TEMA1_MELODIE_H
