//
// Created by Hypericats on 12/10/2024.
//

#include "KeyInputHandler.h"

#include <iostream>

KeyInputHandler::KeyInputHandler(const Window &window) : m_window(window) {
    // Zero out memory
    memset(m_heldKey, 0, sizeof(m_heldKey));
}

void KeyInputHandler::handleEvent(const SDL_Event &event) {
    switch (event.type) {
        case SDL_KEYDOWN: {
            this->setKeyState(event.key.keysym.scancode, 1);
            break;
        }

        case SDL_KEYUP: {
            this->setKeyState(event.key.keysym.scancode, 0);
            break;
        }

        default:
            break;
    }
}

bool KeyInputHandler::isKeyDown(SDL_Keycode keycode) const {
    return getKeyState(keycode); // Cast to bool, 0 is false, 1 is true
}

unsigned char KeyInputHandler::getKeyState(const SDL_Keycode keycode) const {
    // Return matching bit
    return m_heldKey[keycode / 8] & 1 << keycode % 8;
}

void KeyInputHandler::setKeyState(const SDL_Keycode keycode, const unsigned char value) {
    int index = keycode / 8;
    int bit = keycode % 8;
    m_heldKey[index] &= ~(1 << bit);
    m_heldKey[index] |= (value & 1) << bit; // Make sure that value only has 1 bit (1 or 0)
}

void KeyInputHandler::debugStates() const {
    std::cout << "Key States Array :" << std::endl;
    std::cout << "[";
    for (int i = 0; i < KEY_BYTE_COUNT; i++) {
        std::cout << std::to_string(m_heldKey[i]);
        std::cout << ", " << std::endl;
    }
    std::cout << "]" << std::endl;
}

void KeyInputHandler::debugKeys() {
    this->debugStates();
    this->setKeyState(SDL_SCANCODE_W, 1);
    this->setKeyState(SDL_SCANCODE_K, 1);
    this->setKeyState(SDL_SCANCODE_L, 1);
    this->setKeyState(SDL_SCANCODE_M, 1);
    this->setKeyState(SDL_SCANCODE_N, 1);
    this->setKeyState(SDL_SCANCODE_O, 1);
    this->setKeyState(SDL_SCANCODE_K, 0);

    this->debugStates();
    std::cout << "W : " << std::to_string(this->isKeyDown(SDL_SCANCODE_W)) << std::endl;
    std::cout << "K : " << std::to_string(this->isKeyDown(SDL_SCANCODE_K)) << std::endl;
    std::cout << "L : " << std::to_string(this->isKeyDown(SDL_SCANCODE_L)) << std::endl;
    std::cout << "M : " << std::to_string(this->isKeyDown(SDL_SCANCODE_M)) << std::endl;
    std::cout << "N : " << std::to_string(this->isKeyDown(SDL_SCANCODE_N)) << std::endl;
    std::cout << "O : " << std::to_string(this->isKeyDown(SDL_SCANCODE_O)) << std::endl;
}
