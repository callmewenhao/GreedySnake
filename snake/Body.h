//
// Created by zhaowenhao on 2022/7/30.
//

#pragma once
#include <graphics.h>

class Body {
public:
    Body(int x, int y, int d);
    void draw();
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    int getD() const;
    void setD(int d);

private:
    int x;
    int y;
    int d;
    IMAGE body;
};

