//
// Created by zhaowenhao on 2022/7/30.
//

#pragma once
#include <vector>
#include "Head.h"
#include "Body.h"

class Snake {
public:
    Snake(int x, int y, int d, int bodyLen);
    void draw();
    void move(int d);
    void growUp();
    int getX() const;
    int getY() const;

private:
    Head head;
    std::vector<Body> body;
};
