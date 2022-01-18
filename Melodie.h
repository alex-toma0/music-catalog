//
// Created by alext on 11/10/2021.
//

#ifndef TEMA1_MELODIE_H
#define TEMA1_MELODIE_H

#include <iostream>


template <class T> class Melodie;
template <class T> std::ostream& operator<<(std::ostream &out, const Melodie<T>& m);
template <class T>
class Melodie {

protected:
    std::string nume;
    T lungime;
public:

    Melodie(const std::string &nume, T lungime) : nume(nume), lungime(lungime) {};

    const std::string &getNume() const {
        return nume;
    }

    T getLungime() const {
        return lungime;
    }

    // operator <<
    friend std::ostream &operator<< (std::ostream &out, const Melodie<T>& m) {
        out << "Nume: " << m.nume << ", Lungime: " << m.lungime / 60 << ":";
        if (m.lungime % 60 < 10) {
            out << "0" << m.lungime % 60 << "\n";
        } else
            out << m.lungime % 60 << "\n";
        return out;
    }




};


#endif //TEMA1_MELODIE_H
