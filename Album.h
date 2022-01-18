//
// Created by alext on 11/23/2021.
//
#ifndef TEMA1_ALBUM_H
#define TEMA1_ALBUM_H

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <random>
#include "SDL_mixer.h"
#include "SDL.h"
#include "Melodie.h"
#include "Exception.h"
#include "GlobalShuffle.h"

//extern size_t previous_shuffle;

class Album {

protected:
    std::string titlu;
    int lungime, an;
    std::vector<Melodie<int>> melodii;


public:

    // default constructor
    Album() = default;

    // destructor
    ~Album() = default;


    Album(const std::string &titlu,
          const int &an,
          const std::vector<Melodie<int>> &melodii);

    std::string getTitlu() const;

    const std::vector<Melodie<int>> &getMelodii() const;

    int getAn() const;

    // operator <<
    friend std::ostream &operator<<(std::ostream &out, const Album &a);


    // afisare
    virtual std::ostream &printAlbum(std::ostream &out) const = 0;


    // functie care duplica un album (tipul albumului este determinat in clasele derivate)
    virtual std::shared_ptr<Album> clone() const = 0;


    // functie de play, incepand de la indexMelodie (1 <= indexMelodie <= nr. melodii)
    virtual void play(size_t indexMelodie) const;

    virtual void shuffle() const;


};

#endif //TEMA1_ALBUM_H
