//
// Created by alex on 21.12.2021.
//

#include "AlbumFactory.h"
#include "AlbumStudio.h"
#include "Compilatie.h"

std::shared_ptr<Album> AlbumFactory::createAlbum(int tip) {
    Album *album = NULL;
    switch (tip) {
        case 1: {
            album = new AlbumStudio;
            break;
        }
        case 2: {
            album = new Compilatie;
            break;
        }
    }
    if (album == NULL) {
        throw Exception("Tipul obiectului invalid, nu a fost creat");
    }
    return album->clone();
}
