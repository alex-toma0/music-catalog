//
// Created by alex on 07.12.2021.
//

#ifndef MUSIC_CATALOG_ALBUMSTUDIO_H
#define MUSIC_CATALOG_ALBUMSTUDIO_H

#include "Album.h"
#include <iostream>
#include "SDLWrapper.h"

class AlbumStudio : public Album {
private:

public:

    // constr de baza
    AlbumStudio() = default;

    AlbumStudio(const std::string &titlu,
               const int &an,
               const std::vector<Melodie> &melodii);

// afisare
    virtual std::ostream& printAlbum(std::ostream &out) const override;

// functie care creaza un obiect
    std::shared_ptr<Album> duplicateAlbum() const override;

    void play(size_t index_melodie) const;
    void shuffle() const;

};




#endif //MUSIC_CATALOG_ALBUMSTUDIO_H
