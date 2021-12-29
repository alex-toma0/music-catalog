//
// Created by alex on 29.12.2021.
//

#ifndef MUSIC_CATALOG_GLOBALSHUFFLE_H
#define MUSIC_CATALOG_GLOBALSHUFFLE_H
#include <iostream>
class GlobalShuffle {
private:
    size_t val;
    static GlobalShuffle *s_instance;
    GlobalShuffle();
    ~GlobalShuffle() = default;
public:
    const size_t getVal() const;



    static GlobalShuffle *instance() {
        if (!s_instance)
            s_instance = new GlobalShuffle;
        return s_instance;
    }
};


#endif //MUSIC_CATALOG_GLOBALSHUFFLE_H
