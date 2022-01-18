//
// Created by alext on 11/23/2021.
//

#include "Artist.h"
#include <iostream>
#include <memory>



const std::vector<std::shared_ptr<Album>> &Artist::getAlbume() const {
    return albume;
}


Artist::Artist(const std::string &nume, const std::string &genMuzical, const std::string &tara,
               const std::vector<std::shared_ptr<Album>> &albume) : nume(nume), gen_muzical(genMuzical), tara(tara),
                                                                    albume(albume) {}


// constr. de copiere
Artist::Artist(const Artist &a) {
    this->nume = a.nume;
    this->gen_muzical = a.gen_muzical;
    this->tara = a.tara;
    this->albume = a.albume;
}

// operator=
Artist &Artist::operator=(const Artist &a) {

    if (this != &a) {
        this->nume = a.nume;
        this->gen_muzical = a.gen_muzical;
        this->tara = a.tara;
        this->albume = a.albume;
    }
    return *this;
}


// operator <<
std::ostream &operator<<(std::ostream &out, const Artist &a) {
    out << "Nume artist: " << a.nume << ", Gen muzical: " << a.gen_muzical
        << ", Tara: " << a.tara << ", Nr albume: " << a.albume.size()
        << "\nAlbume: \n";
    for (auto &i : a.albume)
        out << *i;

    return out;
}

// functie de search
void Artist::search(std::string tip, std::string item) {
    if (tip == "album") {
        for (auto &i : albume)
            if (i->getTitlu() == item) {
                std::cout << nume << " - " << i->getTitlu();
                return;
            }
        throw Exception("Albumul nu a fost gasit!");

    }

    if (tip == "melodie") {
        for (auto &i : albume) {
            std::vector<Melodie<int>> m = i->getMelodii();
            for (size_t j = 0; j < i->getMelodii().size(); j++)
                if (m[j].getNume() == item) {
                    std::cout << nume << " - " << m[j].getNume() << ", a "
                              << j + 1 << "-a melodie de pe albumul " << i->getTitlu()
                              << "\n";
                    return;
                }
        }

        throw Exception("Melodia nu a fost gasita!");
    }
}

// functie care determina daca doi artisti seamana (bazat pe genul muzical)
void Artist::likeness(const Artist &b) {
    std::vector<std::string> tok;
    std::stringstream gen(gen_muzical);
    std::string temp;
    while (getline(gen, temp, ' ')) {
        tok.push_back(temp);
    }
    for (size_t i = 0; i < tok.size(); i++) {
        if (b.gen_muzical.find(tok[i]) != std::string::npos) {
            std::cout << nume << " similar cu " << b.nume << "\n";
            return;
        }

    }
    std::cout << nume << " nu seamana cu " << b.nume << "\n";
}





