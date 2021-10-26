#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
class Melodie{
private:
    std::string nume, lungime, album;
    int pozitie;
public:
    Melodie(const std::string &nume, const std::string &lungime, const std::string &album, const int &pozitie)
    : nume{nume}, lungime{lungime}, album{album}, pozitie{pozitie} {}

    std::string getNume() {
        return nume;
    }

    std::string getLungime() {
        return lungime;
    }

    std::string getAlbum() {
        return album;
    }

    int getPozitie() {
        return pozitie;
    };

    // operator >>
    friend std::ostream &operator << (std::ostream &out, const Melodie &m) {
        out << "Nume: " << m.nume << ", " << "Lungime: " << m.lungime
        << ", Album: "<< m.album << ", Pozitia pe album: " << m.pozitie << "\n";
        return out;
    }
};

class Album {
private:
    std::string titlu, lungime;
    int nr_melodii, an;
    std::vector<Melodie> melodii;


public:
    std::string getTitlu() {
        return titlu;
    }

    std::string getLungime() {
        return lungime;
    }
    int getNr() {
        return nr_melodii;
    }

    int getAn() {
        return an;
    }

     std::vector<Melodie>& getMelodii() {
        return melodii;
    }

    // constructor init
    Album(const std::string &titlu, const std::string &lungime, const int &nr_melodii,
          const int an,
          const std::vector<Melodie> melodii) : titlu{titlu}, lungime{lungime}, an{an}, nr_melodii{nr_melodii},
          melodii{melodii} {}

    // operator >>
    friend std::ostream &operator << (std::ostream &out, const Album &a) {
        out << "Titlu album: " << a.titlu << ", " << "Lungime: " << a.lungime
            << ", " << "Nr. melodii: " << a.nr_melodii << "\nMelodii:\n";
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

    std::string getNume() {
        return nume;
    }

    std::string getGen() {
        return gen_muzical;
    }

    std::string getTara() {
        return tara;
    }

    int getNr() {
        return nr_albume;
    }

    // constructor init
    Artist(const std::string nume, const std::string gen_muzical, const std::string tara, const int nr_albume,
           const std::vector<Album> albume)
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

    // operator >>
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
            for(int i=0; i<nr_albume; i++)
                for(int j=0; j < albume[i].getNr(); j++)
                    if ( albume[i].getMelodii()[j].getNume() == item) {
                        std::cout << nume << " - " << albume[i].getMelodii()[j].getNume() << ", a "
                                  << albume[i].getMelodii()[j].getPozitie() << "-a melodie "
                                                                               "de pe albumul "
                                  << albume[i].getMelodii()[j].getAlbum()
                                  << "\n";
                        return;
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
    std::vector<Album> a;
    std::vector<Melodie> m;
    m.push_back(Melodie("Battery","5:13","Master of Puppets",1));
    m.push_back(Melodie("Master of Puppets","8:36","Master of Puppets",2));
    m.push_back(Melodie("The Thing That Should Not Be","6:36","Master of Puppets",3));
    m.push_back(Melodie("Welcome Home (Sanitarium)","6:27","Master of Puppets",4));
    m.push_back(Melodie("Disposable Heroes","8:17","Master of Puppets",5));
    m.push_back(Melodie("Leper Messiah","5:40","Master of Puppets",6));
    m.push_back(Melodie("Orion","8:27","Master of Puppets",7));
    m.push_back(Melodie("Damage, Inc.","5:32","Master of Puppets",8));
    a.push_back(Album("Master of Puppets", "54:47", 8, 1986, m));
    Artist metallica("Metallica", "Thrash Metal", "USA", 1 ,a);
    m.clear();
    a.clear();
    m.push_back(Melodie("One More Time","5:20","Discovery",1));
    m.push_back(Melodie("Aerodynamic","3:27","Discovery",2));
    m.push_back(Melodie("Digital Love","4:58","Discovery",3));
    m.push_back(Melodie("Harder, Better, Faster, Stronger","3:45","Discovery",4));
    m.push_back(Melodie("Crescendolis","3:31","Discovery",5));
    m.push_back(Melodie("Nightvision","1:44","Discovery",6));
    m.push_back(Melodie("Superheroes","3:57","Discovery",7));
    m.push_back(Melodie("High Life","3:22","Discovery",8));
    a.push_back(Album("Discovery", "30:40", 8, 2001, m));
    Artist daft_punk("Daft Punk", "House", "France", 1 ,a);
    daft_punk.search("melodie", "Aerodynamic");
    metallica.likeness(daft_punk);



    return 0;
}
