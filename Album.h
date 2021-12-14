//
// Created by alext on 11/23/2021.
//
#ifndef TEMA1_ALBUM_H
#define TEMA1_ALBUM_H

#include <iostream>
#include <vector>
#include <memory>
#include "Melodie.h"

class Album {
private:
    std::string titlu;
    int lungime, an;
    std::vector<Melodie> melodii;

public:

    //constr de baza
    Album();

    // destructor
    ~Album();

    Album(const std::string &titlu,
          const int &an,
          const std::vector<Melodie> &melodii);

    std::string getTitlu() const;

    const std::vector<Melodie> &getMelodii() const;

    int getLungime() const;

    int getNr() const;

    int getAn() const;

// operator <<
    friend std::ostream &operator<<(std::ostream &out, const Album &a);

// afisare
    virtual std::ostream& printAlbum(std::ostream &out) const = 0;



// functie care duplica un album (tipul albumului este determinat in clasele derivate)
    virtual std::shared_ptr<Album> duplicateAlbum() const = 0;


};


#endif //TEMA1_ALBUM_H
