//
// Created by Hypericats on 12/9/2024.
//

#ifndef GAMEOBJECTDISPATCHER_H
#define GAMEOBJECTDISPATCHER_H



class GameObjectDispatcher {
private:
    static inline unsigned long internalID = 0;
    GameObjectDispatcher() = default;
public:
    static unsigned long getNextID() {
        return internalID++;
    }
};



#endif //GAMEOBJECTDISPATCHER_H
