//
// Created by Hypericats on 12/10/2024.
//

#ifndef KEYINPUTHANDLER_H
#define KEYINPUTHANDLER_H
#include <math.h>

#include "../Window.h"


class KeyInputHandler {
public:
    static inline const int KEY_BYTE_COUNT = (int) std::ceil(static_cast<int>(SDL_NUM_SCANCODES) / 8.0F);
    explicit KeyInputHandler(const Window &window);
    void handleEvent(const SDL_Event& event);
    bool isKeyDown(SDL_Keycode keycode) const;

private:
    const Window& m_window;
    unsigned char m_heldKey[KEY_BYTE_COUNT];

    void setKeyState(SDL_Keycode keycode, unsigned char value);
    unsigned char getKeyState(SDL_Keycode keycode) const;
    void debugStates() const;
    void debugKeys();



};



#endif //KEYINPUTHANDLER_H
