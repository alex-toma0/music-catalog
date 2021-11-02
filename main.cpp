#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
class Melodie{
private:
    std::string nume, album;
    int lungime, pozitie;
public:
    Melodie(const std::string &nume, const int &lungime, const std::string &album, const int &pozitie)
    : nume{nume}, lungime{lungime}, album{album}, pozitie{pozitie} {}

    std::string getNume() const {
        return nume;
    }

    int getLungime() const {
        return lungime;
    }

    std::string getAlbum() const {
        return album;
    }

    int getPozitie() const {
        return pozitie;
    }

    // operator <<
    friend std::ostream &operator << (std::ostream &out, const Melodie &m) {
        out << "Nume: " << m.nume << ", Lungime: " << m.lungime / 60 << ":"
        << m.lungime % 60 << ", Album: "<< m.album << ", Pozitia pe album: "
        << m.pozitie << "\n";
        return out;
    }
};

class Album {
private:
    std::string titlu;
    int lungime, nr_melodii, an;
    std::vector<Melodie> melodii;

public:
    std::string getTitlu() const {
        return titlu;
    }

    int getLungime() const {
        return lungime;
    }
    int getNr() const {
        return nr_melodii;
    }

    int getAn() const {
        return an;
    }

     std::vector<Melodie>& getMelodii() {
        return melodii;
    }


    // constructor init
    Album(const std::string &titlu, const int &nr_melodii,
          const int &an,
          const std::vector<Melodie> &melodii) : titlu{titlu},  nr_melodii{nr_melodii}, an{an},
          melodii{melodii} {
        lungime = 0;
        for(int i=0; i<nr_melodii;i++) {
            lungime += melodii[i].getLungime();
        }
    }

    // operator <<
    friend std::ostream &operator << (std::ostream &out, const Album &a) {
        out << "Titlu album: " << a.titlu  << ", Lungime: " << a.lungime / 3600 << ":"
                                             << a.lungime / 60 << ":" << a.lungime % 60
                                             << ", Nr. melodii: " << a.nr_melodii << "\nMelodii:\n";
        for(int i=0; i<a.nr_melodii; i++) {
            out << a.melodii[i];
        }

        return out;
    }
};

class Artist {
private:
    std::string nume,gen_muzical,tara;
    int nr_albume;
    std::vector<Album> albume;

public:

    std::string getNume() const {
        return nume;
    }

    std::string getGen() const {
        return gen_muzical;
    }

    std::string getTara() const {
        return tara;
    }

    int getNr() const {
        return nr_albume;
    }

    // constructor init
    Artist(const std::string &nume, const std::string &gen_muzical, const std::string &tara, const int &nr_albume,
           const std::vector<Album> &albume)
            : nume{nume}, gen_muzical{gen_muzical}, tara{tara}, nr_albume{nr_albume}, albume{albume}  {}

    // constructor de copiere
    Artist(const Artist &a)  {
        this -> nume = a.nume;
        this -> gen_muzical = a.gen_muzical;
        this -> nr_albume = a.nr_albume;
        this -> tara = a.tara;
        this -> albume = a.albume;
    }

    // operator=
    Artist& operator=(const Artist &a) {
        this -> nume = a.nume;
        this -> gen_muzical = a.gen_muzical;
        this -> nr_albume = a.nr_albume;
        this -> tara = a.tara;
        this -> albume = a.albume;
    }

    //destructor
    ~Artist() {

    }

    // operator <<
    friend std::ostream &operator << (std::ostream &out, const Artist &a) {
        out << "Nume artist: " << a.nume << ", Gen muzical: " << a.gen_muzical
             << ", Tara: " << a.tara<< ", Nr albume: " << a.nr_albume << "\nAlbume: \n";
        for (int i=0;i<a.nr_albume;i++)
            out<<a.albume[i];
        return out;
    }

    // functie de search
    void search(std::string tip, std::string item) {
        if (tip == "album") {
            for(int i=0; i<nr_albume; i++)
                if(albume[i].getTitlu() == item) {
                    std::cout << nume << " - " << albume[i].getTitlu();
                    return;
                }
            std::cout << "Albumul nu a fost gasit!" << "\n";
        }

        if (tip == "melodie") {
            for(int i=0; i<nr_albume; i++) {
                std::vector<Melodie> m = albume[i].getMelodii();
                for (int j = 0; j < albume[i].getNr(); j++)
                    if (m[j].getNume() == item) {
                        std::cout << nume << " - " << m[j].getNume() << ", a "
                                  << m[j].getPozitie() << "-a melodie de pe albumul " << m[j].getAlbum()
                                  << "\n";
                        return;
                    }
            }
            std::cout << "Melodia nu a fost gasita!" << "\n";
        }
    }
    // functie care determina daca doi artisti seamana (bazat pe genul muzical)
    void likeness(const Artist &b) {
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
};

int main() {

    // adaugare
    std::vector<Artist> artisti;
    std::vector<Album> albume;
    std::vector<Melodie> melodii;

    melodii.push_back(Melodie("Battery",130,"Master of Puppets",1));
    melodii.push_back(Melodie("Master of Puppets",250,"Master of Puppets",2));
    melodii.push_back(Melodie("The Thing That Should Not Be",333,"Master of Puppets",3));
    melodii.push_back(Melodie("Welcome Home (Sanitarium)",425,"Master of Puppets",4));
    melodii.push_back(Melodie("Disposable Heroes",180,"Master of Puppets",5));
    melodii.push_back(Melodie("Leper Messiah",345,"Master of Puppets",6));
    melodii.push_back(Melodie("Orion",730,"Master of Puppets",7));
    melodii.push_back(Melodie("Damage, Inc.",617,"Master of Puppets",8));



     albume.push_back(Album("Master of Puppets", 8, 1986, melodii));
     Artist metallica("Metallica", "Thrash Metal", "USA", 1 ,albume);
     melodii.clear();
     albume.clear();
     metallica.search("melodie", "Orion");
     std::cout << metallica;

     melodii.push_back(Melodie("One More Time",320,"Discovery",1));
     melodii.push_back(Melodie("Aerodynamic",445,"Discovery",2));
     melodii.push_back(Melodie("Digital Love",458,"Discovery",3));
     melodii.push_back(Melodie("Harder, Better, Faster, Stronger",345,"Discovery",4));
     melodii.push_back(Melodie("Crescendolis",331,"Discovery",5));
     melodii.push_back(Melodie("Nightvision",144,"Discovery",6));
     melodii.push_back(Melodie("Superheroes",357,"Discovery",7));
     melodii.push_back(Melodie("High Life",322,"Discovery",8));
     albume.push_back(Album("Discovery", 8, 2001, melodii));
     Artist daft_punk("Daft Punk", "House", "France", 1 ,albume);
     daft_punk.search("melodie", "Aerodynamic");
     metallica.likeness(daft_punk);



    return 0;
}
