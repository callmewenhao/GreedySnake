//
// Created by zhaowenhao on 2022/7/30.
//

#pragma once

#include <memory>
#include "snake/Snake.h"
#include "Food.h"

class Game {
public:
    Game() {
        snake = std::make_shared<Snake>(400, 350, 3, 4);
        foods = std::make_shared<std::vector<Food>>();
        for (int i = 0; i < foodNum; ++i) {
            foods->emplace_back(200 * (i + 1), 200);
        }
    }
    void drawSnake();
    void drawFoods();
    void eatFoods();
    void update();
    void paint();


private:
    std::shared_ptr<Snake> snake;
    int foodNum = 4;
    std::shared_ptr<std::vector<Food>> foods;
    int eatNum = 0;
    bool isLive = true;

};
