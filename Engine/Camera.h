//
// Created by Hypericats on 12/9/2024.
//

#ifndef CAMERA_H
#define CAMERA_H



class Camera {
private:
    int m_x = 0;
    int m_y = 0;
    float m_zoom = 1.0F;

public:
    int getX() const;
    int getY() const;
    float getZoom() const;

    void setX(int x);
    void setY(int y);
    void setZoom(float zoom);
};



#endif //CAMERA_H
