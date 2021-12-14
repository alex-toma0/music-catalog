
#include "Compilatie.h"

const std::vector<std::string> &Compilatie::getParinte() const {
    return albume_parinte;
}
//constr de baza
Compilatie::Compilatie() {}

Compilatie::Compilatie(const std::string &titlu, const int &an, const std::vector<Melodie> &melodii,
                       const std::vector<std::string> &albume_parinte) : Album(titlu, an, melodii),
                                                                  albume_parinte{albume_parinte} {
}

std::shared_ptr<Album> Compilatie::duplicateAlbum() const {
    return std::make_shared<Compilatie>(*this);
}

std::ostream& Compilatie::printAlbum(std::ostream &out) const {
    out << "Titlu album: " << getTitlu() << ", Lungime: " << getLungime() / 3600 << ":"
        << getLungime() / 60 << ":" << getLungime() % 60
        << ", Nr. melodii: " << getMelodii().size() << "\nMelodii:\n";
    for (size_t i = 0; i < getMelodii().size(); i++) {

        out << i + 1 << ". " << getMelodii()[i] << "de pe albumul " << getParinte()[i] << "\n";
    }

    return out;
}