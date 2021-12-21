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
    std::vector<AlbumStudio> albume_studio;
    std::vector<Compilatie> compilatii;

public:

    const std::vector<AlbumStudio> &getAlbumeStudio() const;

    const std::vector<Compilatie> &getCompilatii() const;

    // constructor de baza
    Artist();

    // constructor init
    Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
           const std::vector<AlbumStudio> &albume_studio, const std::vector<Compilatie> &compilatii);

    Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
           const std::vector<AlbumStudio> &albume_studio);

    Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
           const std::vector<Compilatie> &compilatii);

    Artist(const std::vector<AlbumStudio> &albume_studio);

    Artist(const std::vector<Compilatie> &compilatii);

    // constructor de copiere
    Artist(const Artist &a);

    // operator=
    Artist &operator=(const Artist &a);

    //destructor
    ~Artist();

    // operator <<
    friend std::ostream &operator<<(std::ostream &out, const Artist &a);

    // functie de search pentru un album
    void search(std::string tip, std::string item);

    // functie care determina daca doi artisti seamana (bazat pe genul muzical)
    void likeness(const Artist &b);

    // functii care insereaza albume noi
    void insertAlbumStudio(const AlbumStudio &albume_studio);

};

#endif //TEMA1_ARTIST_H
