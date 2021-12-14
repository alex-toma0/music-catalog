#include <iostream>
#include "Melodie.h"
#include "Album.h"
#include "Artist.h"
#include "Compilatie.h"
#include "AlbumStudio.h"

int main() {


    // adaugare
    Artist Metallica("Metallica", "Thrash Metal", "U.S.A", {
            AlbumStudio("Master of Puppets", 1986, {Melodie("Master of Puppets", 250),
                                                    Melodie("Battery", 130),
                                                    Melodie("The Thing That Should Not Be", 333),
                                                    Melodie("Welcome Home (Sanitarium)", 425),
                                                    Melodie("Disposable Heroes", 180),
                                                    Melodie("Leper Messiah", 345),
                                                    Melodie("Orion", 730),
                                                    Melodie("Damage, Inc.", 617)})});

    Artist DaftPunk("Daft Punk", "House", "France", {
            AlbumStudio("Discovery", 2001, {
                    Melodie("One More Time", 320),
                    Melodie("Aerodynamic", 445),
                    Melodie("Digital Love", 458),
                    Melodie("Harder, Better, Faster, Stronger", 345),
                    Melodie("Crescendolis", 331),
                    Melodie("Nightvision", 144),
                    Melodie("Superheroes", 357),
                    Melodie("High Life", 322),

            })}, {
                            Compilatie("Discovery", 2001, {
                                               Melodie("One More Time", 320),
                                               Melodie("Aerodynamic-c", 445),
                                               Melodie("Digital Love", 458),
                                               Melodie("Harder, Better, Faster, Stronger", 345),
                                               Melodie("Crescendolis", 331),
                                               Melodie("Nightvision", 144),
                                               Melodie("Superheroes", 357),
                                               Melodie("High Life", 322),
                                       },
                                       {"Discovery","Discovery","Discovery","Discovery","Discovery","Discovery","Discovery","Discovery"}
                            )}
    );

    Metallica.search("melodie", "Orion");
    DaftPunk.search("melodie","Aerodynamic-c");
    DaftPunk.likeness(Metallica);



    return 0;
}
