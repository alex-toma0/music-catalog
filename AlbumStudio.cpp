//
// Created by alex on 07.12.2021.
//

#include "AlbumStudio.h"


// constructor init
AlbumStudio::AlbumStudio(const std::string &titlu,
                         const int &an,
                         const std::vector<Melodie> &melodii) : Album(titlu, an, melodii) {
    lungime = 0;
    for (size_t i = 0; i < getMelodii().size(); i++) {
        lungime += melodii[i].lungime;
    }
}

std::shared_ptr<Album> AlbumStudio::duplicateAlbum() const {
    return std::make_shared<AlbumStudio>(*this);
}


// afisare

std::ostream &AlbumStudio::printAlbum(std::ostream &out) const {
    out << "Titlu album: " << titlu << ", Lungime: " << lungime / 3600 << ":"
        << lungime / 60 << ":" << lungime % 60
        << ", Nr. melodii: " << melodii.size() << "\nMelodii:\n";
    for (size_t i = 0; i < melodii.size(); i++) {

        out << i + 1 << ". " << melodii[i];
    }
    return out;
}

// functie de play pentru o melodie
void AlbumStudio::play(size_t index_melodie) const {

    index_melodie--;
    Melodie melodie_curenta = this->melodii[index_melodie];
    std::string path = "songs/" + melodie_curenta.nume + ".wav";
    SDLWrapper player_melodii(path);
    std::cout << "Now playing: " << index_melodie + 1 << ". " << melodie_curenta << "\n";
    std::cout << "Previous (1) /\tNext (2) /\tStop (3)\n";
    unsigned user_input;
    std::cin >> user_input;

    if (index_melodie == this->melodii.size() - 1)
        throw Exception("Albumul s-a terminat!\n");
    if (user_input == 1 && index_melodie > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1 / 4));
        play(index_melodie);
    }

    if (user_input == 2 && index_melodie <= this->melodii.size()) {
        std::this_thread::sleep_for(std::chrono::seconds(1 / 4));
        play(index_melodie + 2);
    }


    if (user_input == 3) {
        player_melodii.~SDLWrapper();
    }
    player_melodii.~SDLWrapper();
}

void AlbumStudio::shuffle() const {

    std::random_device rd;
    std::mt19937 generator(rd());
    static std::uniform_int_distribution<> distr(1, this->melodii.size());
    static std::uniform_int_distribution<> distr_2(1, 2);
    size_t index_melodie = distr(generator);
    size_t previous_shuffle = GlobalShuffle::instance()->getVal();
    index_melodie--;
    if (index_melodie == previous_shuffle && index_melodie != this->melodii.size() - 1) {
        index_melodie = index_melodie + distr_2(generator);
    }

    if (index_melodie == previous_shuffle && index_melodie == this->melodii.size() - 1)
        index_melodie = index_melodie - distr_2(generator);

    Melodie melodie_curenta = this->melodii[index_melodie];
    std::string path = "songs/" + melodie_curenta.nume + ".wav";
    SDLWrapper player_melodii(path);
    std::cout << "Now playing: " << index_melodie + 1 << ". " << melodie_curenta << "\n";
    std::cout << "Previous (1) /\tNext (2) /\tStop (3)\n";
    unsigned user_input;
    std::cin >> user_input;

    if (index_melodie == this->melodii.size() - 1)
        index_melodie = index_melodie - 2;
    if (user_input == 1 && index_melodie > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1 / 4));
        previous_shuffle = index_melodie;
        shuffle();
    }

    if (user_input == 2 && index_melodie <= this->melodii.size()) {
        std::this_thread::sleep_for(std::chrono::seconds(1 / 4));
        previous_shuffle = index_melodie;
        shuffle();
    }


    if (user_input == 3) {
        player_melodii.~SDLWrapper();
    }

    player_melodii.~SDLWrapper();
}


