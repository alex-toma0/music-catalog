//
// Created by alex on 07.12.2021.
//

#include "AlbumStudio.h"
// constr. de baza
AlbumStudio::AlbumStudio() {};
AlbumStudio::AlbumStudio(const std::string &titlu, const int &an, const std::vector<Melodie> &melodii) : Album(titlu,
                                                                                                               an,
                                                                                                               melodii) {};
std::shared_ptr<Album> AlbumStudio::duplicateAlbum() const {
    return std::make_shared<AlbumStudio>(*this);
}


// afisare

std::ostream& AlbumStudio::printAlbum(std::ostream &out) const {
    out << "Titlu album: " << getTitlu() << ", Lungime: " << getLungime() / 3600 << ":"
        << getLungime() / 60 << ":" << getLungime() % 60
        << ", Nr. melodii: " << getMelodii().size() << "\nMelodii:\n";
    for (int i = 0; i < getMelodii().size(); i++) {

        out << i + 1 << ". " << getMelodii()[i];
    }
    return out;
}

