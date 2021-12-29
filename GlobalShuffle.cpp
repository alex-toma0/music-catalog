//
// Created by alex on 29.12.2021.
//

#include "GlobalShuffle.h"

GlobalShuffle* GlobalShuffle::s_instance = nullptr;
GlobalShuffle::GlobalShuffle() {
    val = -1;
}

const size_t GlobalShuffle::getVal() const {
    return val;
}



