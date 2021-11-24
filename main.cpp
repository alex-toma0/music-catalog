#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Melodie.h"
#include "Album.h"
#include "Artist.h"
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



     albume.push_back(Album("Master of Puppets",1986, melodii));
     Artist metallica("Metallica", "Thrash Metal", "USA", albume);
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
     albume.push_back(Album("Discovery", 2001, melodii));
     Artist daft_punk("Daft Punk", "House", "France", albume);
     daft_punk.search("melodie", "Aerodynamic");
     metallica.likeness(daft_punk);



    return 0;
}
