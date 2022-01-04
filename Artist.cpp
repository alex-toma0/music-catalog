//
// Created by alext on 11/23/2021.
//

#include "Artist.h"
#include <iostream>
#include <memory>


const std::vector<AlbumStudio> &Artist::getAlbumeStudio() const {
    return albume_studio;
}

const std::vector<Compilatie> &Artist::getCompilatii() const {
    return compilatii;
}

// constr. de baza
Artist::Artist() {}

Artist::Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
               const std::vector<AlbumStudio> &albume_studio, const std::vector<Compilatie> &compilatii)
        : nume{nume}, gen_muzical{gen_muzical}, tara{tara}, albume_studio{albume_studio}, compilatii{compilatii} {}

Artist::Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
               const std::vector<AlbumStudio> &albume_studio)
        : nume{nume}, gen_muzical{gen_muzical}, tara{tara}, albume_studio{albume_studio} {}

Artist::Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
               const std::vector<Compilatie> &compilatii)
        : nume{nume}, gen_muzical{gen_muzical}, tara{tara}, compilatii{compilatii} {}

Artist::Artist(const std::vector<AlbumStudio> &albume_studio) : albume_studio{albume_studio} {}

Artist::Artist(const std::vector<Compilatie> &compilatii) : compilatii{compilatii} {}


// constr. de copiere
Artist::Artist(const Artist &a) {
    this->nume = a.nume;
    this->gen_muzical = a.gen_muzical;
    this->tara = a.tara;
    this->albume_studio = a.albume_studio;
    this->compilatii = a.compilatii;
}

// operator=
Artist &Artist::operator=(const Artist &a) {

    if (this != &a) {
        this->nume = a.nume;
        this->gen_muzical = a.gen_muzical;
        this->tara = a.tara;
        this->albume_studio = a.albume_studio;
        this->compilatii = a.compilatii;
    }
    return *this;
}

//destructor
Artist::~Artist() {

}

// operator <<
std::ostream &operator<<(std::ostream &out, const Artist &a) {
    out << "Nume artist: " << a.nume << ", Gen muzical: " << a.gen_muzical
        << ", Tara: " << a.tara << ", Nr albume: " << a.albume_studio.size() + a.compilatii.size()
        << "\nAlbume Studio: \n";
    for (size_t i = 0; i < a.albume_studio.size(); i++)
        out << a.albume_studio[i];

    out << "\nCompilatii: \n";

    for (size_t i = 0; i < a.compilatii.size(); i++)
        out << a.compilatii[i];
    return out;

}

// functie de search
void Artist::search(std::string tip, std::string item) {
    if (tip == "album") {
        for (size_t i = 0; i < albume_studio.size(); i++)
            if (albume_studio[i].getTitlu() == item) {
                std::cout << nume << " - " << albume_studio[i].getTitlu();
                return;
            }


        for (size_t i = 0; i < compilatii.size(); i++)
            if (compilatii[i].getTitlu() == item) {
                std::cout << nume << " - " << compilatii[i].getTitlu();
                return;

            }
        std::throw_with_nested("Albumul nu a fost gasit!");

    }

    if (tip == "melodie") {
        for (size_t i = 0; i < albume_studio.size(); i++) {
            std::vector<Melodie> m = albume_studio[i].getMelodii();
            for (size_t j = 0; j < albume_studio[i].getMelodii().size(); j++)
                if (m[j].getNume() == item) {
                    std::cout << nume << " - " << m[j].getNume() << ", a "
                              << j + 1 << "-a melodie de pe albumul " << albume_studio[i].getTitlu()
                              << "\n";
                    return;
                }
        }
        for (size_t i = 0; i < compilatii.size(); i++) {
            std::vector<Melodie> m = compilatii[i].getMelodii();
            for (size_t j = 0; j < compilatii[i].getMelodii().size(); j++)
                if (m[j].getNume() == item) {
                    std::cout << nume << " - " << m[j].getNume() << ", a "
                              << j + 1 << "-a melodie de pe compilatia " << compilatii[i].getTitlu()
                              << "\n";
                    return;
                }
        }
        std::throw_with_nested("Melodia nu a fost gasita!");
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

// functii care insereaza albume noi
void Artist::insertAlbumStudio(const AlbumStudio &album_studio) {

    albume_studio.push_back(album_studio);

}


