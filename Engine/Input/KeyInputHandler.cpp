//
// Created by Hypericats on 12/10/2024.
//

#include "KeyInputHandler.h"

KeyInputHandler::KeyInputHandler(Window &window) : m_window(window) {
    // Zero out memory
    memset(m_heldKey, 0, sizeof(m_heldKey));
}

void KeyInputHandler::handleEvent(const SDL_Event &event) const {
    switch (event.type) {
        case SDL_KEYDOWN: {
            printf("Key Down\n");
            if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                this->m_window.getCamera().setY(m_window.getCamera().getY() + 10);
            }

            break;
        }

        case SDL_KEYUP: {
            printf("Key Up\n");
            break;
        }

        default:
            break;
    }


}

bool KeyInputHandler::isKeyDown(SDL_Keycode keycode) const {
    return getKeyState(keycode); // this may be incorrect
    LOOK ABOVE ^^
}

bool KeyInputHandler::frameUpdate() {
    // Give listeners update

}

unsigned char KeyInputHandler::getKeyState(const SDL_Keycode keycode) const {
    // Return matching bit
    return m_heldKey[keycode / 8] & 1 << keycode % 8;
    I THINK THIS WORKS
    STILL NEED TO INPUT THEM INTO ARRAY ABOVE
}

void KeyInputHandler::setKeyState(SDL_Keycode keycode, unsigned char value) {
    m_heldKey[keycode / 8] |= 1 << keycode % 8;
    NOTE DONE
}
