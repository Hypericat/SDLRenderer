//
// Created by Hypericats on 12/9/2024.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "Math/Vector2i.h"


class Camera {
private:
    Vector2i m_cameraPosition = Vector2i(0, 0);
    float m_zoom = 1.0F;

public:
    Vector2i& getPos();
    int getX() const;
    int getY() const;
    float getZoom() const;

    void setX(int x);
    void setY(int y);
    void setPos(const Vector2i& pos);
    void setZoom(float zoom);

};



#endif //CAMERA_H
