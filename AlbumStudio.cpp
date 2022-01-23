//
// Created by alex on 07.12.2021.
//

#include "AlbumStudio.h"


// constructor init
AlbumStudio::AlbumStudio(const std::string &titlu,
                         const int &an,
                         const std::vector<Melodie<int>> &melodii) : Album(titlu, an, melodii) {
    lungime = 0;
    for (size_t i = 0; i < getMelodii().size(); i++) {
        lungime += melodii[i].getLungime();
    }
}

std::shared_ptr<Album> AlbumStudio::clone() const {
    return std::make_shared<AlbumStudio>(*this);
}


// afisare

std::ostream &AlbumStudio::printAlbum(std::ostream &out) const {
    out << "Titlu album: " << titlu << ", Lungime: " << lungime / 3600 << ":"
        << lungime / 60 << ":" << lungime % 60
        << ", Nr. melodii: " << melodii.size() << "\nMelodii:\n";
    for (size_t i = 0; i < melodii.size(); i++) {

        out << i + 1 << ". " << melodii[i];
    }
    return out;
}

void AlbumStudio::variety() const {
    std::cout << "0% varietate, melodiile sunt de pe acelasi album\n";
}





