//
// Created by alext on 11/23/2021.
//

#include "Artist.h"
#include <iostream>


std::string Artist::getNume() const {
return nume;
}

std::string Artist::getGen() const {
return gen_muzical;
}

std::string Artist::getTara() const {
return tara;
}

Artist::Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara,
   const std::vector<Album> &albume)
    : nume{nume}, gen_muzical{gen_muzical}, tara{tara}, albume{albume}  {}


Artist::Artist(const Artist &a)  {
this -> nume = a.nume;
this -> gen_muzical = a.gen_muzical;
this -> tara = a.tara;
this -> albume = a.albume;
}

// operator=
Artist& Artist::operator=(const Artist &a) {
this -> nume = a.nume;
this -> gen_muzical = a.gen_muzical;
this -> tara = a.tara;
this -> albume = a.albume;
}

//destructor
Artist::~Artist() {

}

// operator <<
std::ostream &operator << (std::ostream &out, const Artist &a) {
out << "Nume artist: " << a.nume << ", Gen muzical: " << a.gen_muzical
    << ", Tara: " << a.tara<< ", Nr albume: " << a.albume.size() << "\nAlbume: \n";
for (int i=0;i<a.albume.size();i++)
    out<<a.albume[i];
return out;
}

// functie de search
void Artist::search(std::string tip, std::string item) {
if (tip == "album") {
    for(int i=0; i<albume.size(); i++)
        if(albume[i].getTitlu() == item) {
            std::cout << nume << " - " << albume[i].getTitlu();
            return;
        }
    std::cout << "Albumul nu a fost gasit!" << "\n";
}

if (tip == "melodie") {
    for (int i=0; i<albume.size(); i++) {
        std::vector<Melodie> m = albume[i].getMelodii();
        for (int j = 0; j < albume[i].getMelodii().size(); j++)
            if (m[j].getNume() == item) {
                std::cout << nume << " - " << m[j].getNume() << ", a "
                          << j+1 << "-a melodie de pe albumul " << albume[i].getTitlu()
                          << "\n";
                return;
            }
    }
    std::cout << "Melodia nu a fost gasita!" << "\n";
}
}

// functie care determina daca doi artisti seamana (bazat pe genul muzical)
void Artist::likeness(const Artist &b) {
std::vector<std::string> tok;
std::stringstream gen(gen_muzical);
std::string temp;
while (getline(gen, temp, ' '))
{
    tok.push_back(temp);
}
for (int i=0;i<tok.size();i++) {
    if (b.gen_muzical.find(tok[i]) != std::string::npos) {
        std::cout << nume << " similar cu " << b.nume << "\n";
        return;
    }

}
std::cout << nume << " nu seamana cu " << b.nume << "\n";

}
