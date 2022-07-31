//
// Created by zhaowenhao on 2022/7/31.
//

#include "Food.h"

Food::Food(int x, int y): x(x), y(y) {
    loadimage(&food, _T("resources/food.png"));
}

void Food::draw() {
    putimage(x, y, &food);
}

bool Food::getLive() const {
    return isLive;
}

void Food::setLive(bool isLive) {
    Food::isLive = isLive;
}

int Food::getX() const {
    return x;
}

int Food::getY() const {
    return y;
}

