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
    artisti.push_back(Artist("Metallica","Thrash Metal", "U.S.A", {
        Album("Master of Puppets",1986,{Melodie("Master of Puppets",250),
               Melodie("Battery",130),
               Melodie("The Thing That Should Not Be",333),
               Melodie("Welcome Home (Sanitarium)",425),
               Melodie("Disposable Heroes",180),
               Melodie("Leper Messiah",345),
               Melodie("Orion",730),
               Melodie("Damage, Inc.",617)})}));



     artisti[0].search("melodie", "Orion");
     std::cout << artisti[0];

     artisti.push_back(Artist("Daft Punk","House","France",{
         Album("Discovery",2001,{
                 Melodie("One More Time",320),
                 Melodie("Aerodynamic",445),
                 Melodie("Digital Love",458),
                 Melodie("Harder, Better, Faster, Stronger",345),
                 Melodie("Crescendolis",331),
                 Melodie("Nightvision",144),
                 Melodie("Superheroes",357),
                 Melodie("High Life",322),

         })}));


     artisti[1].search("melodie", "Aerodynamic");
     artisti[0].likeness(artisti[1]);





    return 0;
}
