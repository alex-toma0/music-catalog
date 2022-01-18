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
               const std::vector<Melodie<int>> &melodii);

// afisare
    std::ostream& printAlbum(std::ostream &out) const override;

    std::shared_ptr<Album> clone() const override;


};




#endif //MUSIC_CATALOG_ALBUMSTUDIO_H
