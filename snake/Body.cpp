//
// Created by zhaowenhao on 2022/7/30.
//

#include "Body.h"



Body::Body(int x, int y, int d): x(x), y(y), d(d) {
    loadimage(&body, _T("resources/body.png"));
}

void Body::draw() {
    putimage(x, y, &body);
}

int Body::getX() const {
    return x;
}

int Body::getY() const {
    return y;
}

void Body::setX(int x) {
    Body::x = x;
}

void Body::setY(int y) {
    Body::y = y;
}

int Body::getD() const {
    return d;
}

void Body::setD(int d) {
    Body::d = d;
}


