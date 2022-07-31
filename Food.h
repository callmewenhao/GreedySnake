//
// Created by zhaowenhao on 2022/7/31.
//

#pragma once
#include <graphics.h>

class Food {
public:
    Food(int x, int y);
    void draw();
    bool getLive() const;
    void setLive(bool isLive);
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
    bool isLive = true;
    IMAGE food;
};
