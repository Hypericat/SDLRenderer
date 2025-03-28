//
// Created by Hypericats on 12/14/2024.
//

#ifndef DIRECTION_H
#define DIRECTION_H
#include <string>

#endif //DIRECTION_H

class Direction {
public:
    enum ENUM {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    static void negate(ENUM& enumerator) {
        if (enumerator == NONE) return;
        if (enumerator == UP) {
            enumerator = DOWN;
            return;
        }

        if (enumerator == DOWN) {
            enumerator = UP;
            return;
        }

        if (enumerator == LEFT) {
            enumerator = RIGHT;
            return;
        }

        enumerator = LEFT;
    }
    static void toString(const ENUM& enumerator, std::string& inStr) {
        if (enumerator == NONE) {
            inStr = "None";
            return;
        }
        if (enumerator == LEFT) {
            inStr = "Left";
            return;
        }
        if (enumerator == RIGHT) {
            inStr = "Right";
            return;
        }
        if (enumerator == UP) {
            inStr = "Up";
            return;
        }
        if (enumerator == DOWN) {
            inStr = "Down";
            return;
        }
    }
};