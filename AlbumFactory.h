//
// Created by alex on 21.12.2021.
//

#ifndef MUSIC_CATALOG_ALBUMFACTORY_H
#define MUSIC_CATALOG_ALBUMFACTORY_H


#include "Album.h"

class AlbumFactory {
public:
    static std::shared_ptr<Album> createAlbum(int tip);


};


#endif //MUSIC_CATALOG_ALBUMFACTORY_H
