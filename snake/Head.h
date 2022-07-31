//
// Created by zhaowenhao on 2022/7/30.
//

#pragma once
#include <graphics.h>

class Head {
public:
    Head(int x, int y, int d);
    void draw();
    void move(int d);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getD() const;
    void setD(int d);

private:
    int x;
    int y;
    int d;
    IMAGE headUp;
    IMAGE headRight;
    IMAGE headDown;
    IMAGE headLeft;

};
