//
// Created by alex on 04.01.2022.
//

#ifndef MUSIC_CATALOG_SDLWRAPPER_H
#define MUSIC_CATALOG_SDLWRAPPER_H

#include "SDL.h"
#include "SDL_mixer.h"
#include <string>
#include <cstring>
#include "Exception.h"

class SDLWrapper {
private:
    Mix_Music *music;
public:
    SDLWrapper(std::string path);

    ~SDLWrapper();


};


#endif //MUSIC_CATALOG_SDLWRAPPER_H
