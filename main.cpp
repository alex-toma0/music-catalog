
#include <iostream>
#include "Melodie.h"
#include "Album.h"
#include "Artist.h"
#include "Compilatie.h"
#include "AlbumStudio.h"
#include "Exception.h"
#include "AlbumFactory.h"
#include "GlobalShuffle.h"

#undef main // pentru compatibilitate pe windows
int main() {


    // adaugare
    Artist Metallica("Metallica", "Thrash Metal", "U.S.A", {
                             AlbumStudio("Master of Puppets", 1986, {Melodie("Master Of Puppets", 250),
                                                                     Melodie("Battery", 130),
                                                                     Melodie("The Thing That Should Not Be", 333),
                                                                     Melodie("Welcome Home(Sanitarium)", 425),
                                                                     Melodie("Disposable Heroes", 180),
                                                                     Melodie("Leper Messiah", 345),
                                                                     Melodie("Orion", 730),
                                                                     Melodie("Damage, Inc.", 617)})},
                     {
                             Compilatie("Master of Puppets", 1986, {Melodie("Master Of Puppets", 250),
                                                                    Melodie("Battery", 130),
                                                                    Melodie("The Thing That Should Not Be", 333),
                                                                    Melodie("Welcome Home(Sanitarium)", 425),
                                                                    Melodie("Disposable Heroes", 180),
                                                                    Melodie("Leper Messiah", 345),
                                                                    Melodie("Orion", 730),
                                                                    Melodie("Damage, Inc.", 617)},
                                        {"Master of Puppets", "Master of Puppets", "Master of Puppets",
                                         "Master of Puppets", "Master of Puppets", "Master of Puppets",
                                         "Master of Puppets", "Master of Puppets"})}


    );

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
                                       {"Discovery", "Discovery", "Discovery", "Discovery", "Discovery", "Discovery",
                                        "Discovery", "Discovery"}
                            )}
    );

    //std::cout << Metallica;

    try {
        // play la prima compilatie, incepand de la prima melodie.
        //Metallica.getCompilatii()[0].play(1);
        Metallica.getCompilatii()[0].shuffle();

    }
    catch (
            Exception &e
    ) {
        std::cout << e.

                what();

    }



    //Album* a = AlbumFactory::createAlbum(1);
    //std::cout << a;

    return 0;
}

