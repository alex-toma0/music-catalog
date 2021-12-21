//
// Created by alext on 11/10/2021.
//

#ifndef TEMA1_MELODIE_H
#define TEMA1_MELODIE_H

#include <iostream>

class Melodie {
    friend class Album;

    friend class AlbumStudio;

    friend class Compilatie;

protected:
    std::string nume;
    int lungime;
public:

    Melodie(const std::string &nume, const int &lungime);

    std::string getNume() const;

    int getLungime() const;

    // operator <<
    friend std::ostream &operator<<(std::ostream &out, const Melodie &m);


};

#endif //TEMA1_MELODIE_H
