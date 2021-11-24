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

class Artist {
private:
    std::string nume,gen_muzical,tara;
    std::vector<Album> albume;

public:

    std::string getNume() const;
    std::string getGen() const;
    std::string getTara() const;
    int getNr() const;

    // constructor init
    Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
           const std::vector<Album> &albume);
    // constructor de copiere
    Artist(const Artist &a);

    // operator=
    Artist& operator=(const Artist &a);

    //destructor
    ~Artist();

    // operator <<
    friend std::ostream &operator << (std::ostream &out, const Artist &a);

    // functie de search
    void search(std::string tip, std::string item);

    // functie care determina daca doi artisti seamana (bazat pe genul muzical)
    void likeness(const Artist &b);

};

#endif //TEMA1_ARTIST_H
