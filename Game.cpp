//
// Created by zhaowenhao on 2022/7/30.
//
#include <thread>
#include <graphics.h>
#include <string>
#include <random>
#include "Game.h"

char buf[10];
std::uniform_int_distribution<unsigned> randomX(0, (1000 - 25) / 25);
std::uniform_int_distribution<unsigned> randomY(0, (700 - 25) / 25);
std::default_random_engine e;

void Game::drawSnake() {
    snake->draw();
}

void Game::update() {
    ExMessage exMessage;
    while (isLive) {
        if (peekmessage(&exMessage, EM_KEY, true)) {
            // get message from message queue
            if (exMessage.message == WM_KEYDOWN) {
                switch (exMessage.vkcode) {
                    case VK_UP:
                        snake->move(0);
                        break;
                    case VK_RIGHT:
                        snake->move(1);
                        break;
                    case VK_DOWN:
                        snake->move(2);
                        break;
                    case VK_LEFT:
                        snake->move(3);
                        break;
                    case VK_ESCAPE:
                    {
                        HWND hWnd = GetHWnd();
                        int choose = MessageBox(hWnd, "do you want to exit?", "Hi bro!" ,MB_OKCANCEL);
                        if(choose == IDOK) {
                            isLive = false;
                        }
                    }
                    break;
                    default:break;
                }
            }
        }
        // sleep 100 ms
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Game::paint() {
    while (isLive) {
        // eat foodQ
        eatFoods();

        // paint panel each frame
        BeginBatchDraw();
        cleardevice();
        sprintf(buf, "eat:%03d", eatNum);
        settextstyle(30, 0, _T("Consolas"));
        outtextxy(800, 50, buf);
        drawFoods();
        drawSnake();
        EndBatchDraw();

        // sleep 100 ms
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

}

void Game::drawFoods() {
    if (foods->size() < foodNum) {
        int x = randomX(e) * 25;
        int y = randomY(e) * 25;
        foods->emplace_back(x, y);
    }
    for (auto it = foods->begin(); it != foods->end();) {
        if (it->getLive()) {
            it->draw();
            ++it;
        } else {
            it = foods->erase(it);
        }
    }
}

void Game::eatFoods() {
    for (auto it = foods->begin(); it != foods->end(); ++it) {
        if (it->getLive() && it->getX() == snake->getX() && it->getY() == snake->getY()) {
            it->setLive(false);
            snake->growUp();
            ++eatNum;
        }
    }
}
