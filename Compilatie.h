
#ifndef MUSIC_CATALOG_COMPILATIE_H
#define MUSIC_CATALOG_COMPILATIE_H

#include "Album.h"
#include "AlbumStudio.h"
#include <iostream>
#include <map>


class Compilatie : public Album {
private:
    std::vector<std::string> albume_parinte;

public:

    const std::vector<std::string> &getParinte() const;

// constr de baza
    Compilatie() = default;

    Compilatie(const std::string &titlu,
               const int &an,
               const std::vector<Melodie<int>> &melodii, const std::vector<std::string> &albume_parinte);

// afisare
    virtual std::ostream& printAlbum(std::ostream &out) const override;

// functie de duplicare
    std::shared_ptr<Album> clone() const override;

    virtual void variety() const override;
};


#endif //MUSIC_CATALOG_COMPILATIE_H
