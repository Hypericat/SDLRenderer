//
// Created by Hypericats on 12/10/2024.
//

#ifndef KEYINPUTHANDLER_H
#define KEYINPUTHANDLER_H
#include <math.h>
#include <unordered_set>

#include "../Window.h"


class KeyInputHandler {
public:
    static inline const int KEY_BYTE_COUNT = (int) std::ceil(SDL_NUM_SCANCODES / 8.0F);
    KeyInputHandler(Window &window);
    void handleEvent(const SDL_Event& event) const;
    bool isKeyDown(SDL_Keycode keycode) const;
    bool frameUpdate();
    
private:
    Window& m_window;
    unsigned char m_heldKey[KEY_BYTE_COUNT];
    unsigned char getKeyState(SDL_Keycode keycode) const;
    void setKeyState(SDL_Keycode keycode, unsigned char value) const;
};



#endif //KEYINPUTHANDLER_H
