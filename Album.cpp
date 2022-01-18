//
// Created by alext on 11/23/2021.
//

#include "Album.h"
#include "SDLWrapper.h"

//size_t previous_shuffle = -1;

std::string Album::getTitlu() const {
    return titlu;
}

const std::vector<Melodie<int>> &Album::getMelodii() const {
    return melodii;
}


int Album::getAn() const {
    return an;
}


// constructor init
Album::Album(const std::string &titlu,
             const int &an,
             const std::vector<Melodie<int>> &melodii) : titlu{titlu}, an{an}, melodii{melodii} {
    lungime = 0;
    for (size_t i = 0; i < getMelodii().size(); i++) {
        lungime += melodii[i].getLungime();
    }
}

// functia virtuala printAlbum se va ocupa de afisare
std::ostream &operator<<(std::ostream &out, const Album &a) {
    return a.printAlbum(out);

}

void Album::play(size_t index_melodie) const {

    index_melodie--;
    Melodie<int> melodie_curenta = this->melodii[index_melodie];
    std::string path = "songs/" + melodie_curenta.getNume() + ".wav";
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

}

void Album::shuffle() const {

    static std::random_device rd;
    static std::mt19937 generator(rd());
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

    Melodie<int> melodie_curenta = this->melodii[index_melodie];
    std::string path = "songs/" + melodie_curenta.getNume() + ".wav";
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

}





