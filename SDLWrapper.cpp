//
// Created by alex on 04.01.2022.
//

#include "SDLWrapper.h"


SDLWrapper::SDLWrapper(std::string path) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        throw Exception(SDL_GetError());
    }

    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2024) < 0) {
        throw Exception(Mix_GetError());
    }

    music = Mix_LoadMUS(path.c_str());
    if (music == NULL) {
        throw Exception(Mix_GetError());
    }

    Mix_PlayMusic(music, 1);
}

SDLWrapper::~SDLWrapper() {
    Mix_FreeMusic(music);
    SDL_Quit();
}