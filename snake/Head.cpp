//
// Created by zhaowenhao on 2022/7/30.
//

#include "Head.h"

extern const int panelWidth;
extern const int panelHeight;

Head::Head(int x, int y, int d) : x(x), y(y), d(d) {
    loadimage(&headUp, _T("resources/up.png"));
    loadimage(&headRight, _T("resources/right.png"));
    loadimage(&headDown, _T("resources/down.png"));
    loadimage(&headLeft, _T("resources/left.png"));
}

void Head::move(int d) {
    switch (d) {
        case 0:
            if(y == 0){
                y = panelHeight - 25;
            } else {
                y -= 25;
            }
            break;
        case 1:
            if(x == panelWidth - 25) {
                x = 0;
            } else {
                x += 25;
            }
            break;
        case 2:
            if(y == panelHeight - 25) {
                y = 0;
            } else {
                y += 25;
            }
            break;
        case 3:
            if(x == 0) {
                x = panelWidth - 25;
            } else {
                x -= 25;
            }
            break;
        default:break;
    }
}

void Head::draw() {
    switch (d) {
        case 0:
            putimage(x, y, &headUp);
            break;
        case 1:
            putimage(x, y, &headRight);
            break;
        case 2:
            putimage(x, y, &headDown);
            break;
        case 3:
            putimage(x, y, &headLeft);
            break;
        default:break;
    }
}

int Head::getD() const {
    return d;
}

void Head::setD(int d) {
    Head::d = d;
}

int Head::getX() const {
    return x;
}

void Head::setX(int x) {
    Head::x = x;
}

int Head::getY() const {
    return y;
}

void Head::setY(int y) {
    Head::y = y;
}


