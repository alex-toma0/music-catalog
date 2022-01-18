//
// Created by alext on 11/23/2021.
//

#ifndef TEMA1_ARTIST_H
#define TEMA1_ARTIST_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Album.h"
#include "Compilatie.h"
#include "AlbumStudio.h"

class Artist {
private:
    std::string nume, gen_muzical, tara;
    std::vector<std::shared_ptr<Album>> albume;

public:

    const std::vector<std::shared_ptr<Album>> &getAlbume() const;


    Artist() = default;

    // constructor init

    Artist(const std::string &nume, const std::string &genMuzical, const std::string &tara,
           const std::vector<std::shared_ptr<Album>> &albume);


    // constructor de copiere
    Artist(const Artist &a);

    // operator=
    Artist &operator=(const Artist &a);

    //destructor
    ~Artist() = default;

    // operator <<
    friend std::ostream &operator<<(std::ostream &out, const Artist &a);

    // functie de search pentru un album/ melodie
    void search(std::string tip, std::string item);

    // functie care determina daca doi artisti seamana (bazat pe genul muzical)
    void likeness(const Artist &b);


};

#endif //TEMA1_ARTIST_H
