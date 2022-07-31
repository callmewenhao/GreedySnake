//
// Created by zhaowenhao on 2022/7/30.
//

#include "Snake.h"

Snake::Snake(int x, int y, int d, int bodyLen) : head(x, y, d) {
    int xBody = x;
    int yBody = y;
    for (int i = 0; i < bodyLen; ++i) {
        xBody += 25;
        body.emplace_back(xBody, yBody, d);
    }
}

void Snake::draw() {
    // draw head
    head.draw();
    // draw body
    for (auto it = body.begin(); it != body.end(); ++it) {
        it->draw();
    }
}

void Snake::move(int d) {
    if (d == (head.getD() + 2) % 4) {
        return;
    }
    // body
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setX(body[i - 1].getX());
        body[i].setY(body[i - 1].getY());
        body[i].setD(body[i - 1].getD());
    }
    body[0].setX(head.getX());
    body[0].setY(head.getY());
    body[0].setD(head.getD());
    // head
    head.setD(d);
    head.move(d);
}

int Snake::getX() const {
    return head.getX();
}

int Snake::getY() const {
    return head.getY();
}

void Snake::growUp() {
    int lastX = body.back().getX();
    int lastY = body.back().getY();
    int lastD = body.back().getD();
    switch (lastD) {
        case 0:
            body.emplace_back(lastX, lastY + 25, lastD);
            break;
        case 1:
            body.emplace_back(lastX - 25, lastY, lastD);
            break;
        case 2:
            body.emplace_back(lastX, lastY - 25, lastD);
            break;
        case 3:
            body.emplace_back(lastX + 25, lastY, lastD);
            break;
        default:break;
    }

}
