
#include <iostream>
#include "Melodie.h"
#include "Album.h"
#include "Artist.h"
#include "Compilatie.h"
#include "AlbumStudio.h"
#include "Exception.h"
#include "AlbumFactory.h"
#include "GlobalShuffle.h"
#include "tempPrint.h"

#undef main

int main(int argc, char **argv) {


    //adaugare in baza de date
    Artist DaftPunk("Daft Punk", "House", "France", {
            AlbumStudio("Discovery", 2001, {
                    Melodie<int>("One More Time", 320),
                    Melodie<int>("Aerodynamic", 445),
                    Melodie<int>("Digital Love", 458),
                    Melodie<int>("Harder, Better, Faster, Stronger", 345),
                    Melodie<int>("Crescendolis", 331),
                    Melodie<int>("Nightvision", 144),
                    Melodie<int>("Superheroes", 357),
                    Melodie<int>("High Life", 322),

            }).clone(),
            Compilatie("Discovery", 2001, {
                               Melodie<int>("One More Time", 320),
                               Melodie<int>("Aerodynamic-c", 445),
                               Melodie<int>("Digital Love", 458),
                               Melodie<int>("Harder, Better, Faster, Stronger", 345),
                               Melodie<int>("Crescendolis", 331),
                               Melodie<int>("Nightvision", 144),
                               Melodie<int>("Superheroes", 357),
                               Melodie<int>("High Life", 322),
                       },
                       {"Discovery", "Discovery", "Discovery", "Discovery", "Discovery", "Discovery",
                        "Discovery", "Discovery"}
            ).clone()}
    );

    Artist Metallica("Metallica", "Thrash Metal", "U.S.A", {
            AlbumStudio("Master of Puppets", 1986, {Melodie<int>("Master Of Puppets", 250),
                                                    Melodie<int>("Battery", 130),
                                                    Melodie<int>("The Thing That Should Not Be", 333),
                                                    Melodie<int>("Welcome Home(Sanitarium)", 425),
                                                    Melodie<int>("Disposable Heroes", 180),
                                                    Melodie<int>("Leper Messiah", 345),
                                                    Melodie<int>("Orion", 730),
                                                    Melodie<int>("Damage, Inc.", 617)}).clone(),

            Compilatie("Master of Puppets", 1986, {Melodie<int>("Master Of Puppets", 250),
                                                   Melodie<int>("Battery", 130),
                                                   Melodie<int>("The Thing That Should Not Be", 333),
                                                   Melodie<int>("Welcome Home(Sanitarium)", 425),
                                                   Melodie<int>("Disposable Heroes", 180),
                                                   Melodie<int>("Leper Messiah", 345),
                                                   Melodie<int>("Orion", 730),
                                                   Melodie<int>("Damage, Inc.", 617)},
                       {"Master of Puppets", "Master of Puppets", "Master of Puppets",
                        "Master of Puppets", "Master of Puppets", "Master of Puppets",
                        "Master of Puppets", "Master of Puppets"}).clone()}


    );

    // functia de likeness+ functia de search
    //Metallica.likeness(DaftPunk);
    //Metallica.search("melodie","Battery");





    try {

        // play + shuffle
        //Metallica.getAlbume()[0]->play(1);
        Metallica.getAlbume()[1]->shuffle();

    }
    catch (
            Exception &e
    ) {
        std::cout << e.

                what();

    }


    // exemplificare factory
    //std::shared_ptr<Album> af = AlbumFactory::createAlbum(1);
    //std::cout << *af;

    //functie template
    // tempPrint(Metallica);


    return 0;
}

