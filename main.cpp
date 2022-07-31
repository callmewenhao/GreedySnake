#include <iostream>
#include <graphics.h>
#include <thread>
#include "Game.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


extern const int panelWidth = 1000;
extern const int panelHeight = 700;

int main() {
    // play the music
    PlaySound(TEXT("resources/music.wav"), nullptr, SND_FILENAME | SND_ASYNC | SND_LOOP );
    initgraph(panelWidth, panelHeight);    // init the windows

    Game game;
    std::thread updateInfo(&Game::update, &game);
    std::thread repaint(&Game::paint, &game);
    repaint.join();
    updateInfo.join();

//    system("pause");
    closegraph();            // 关闭绘图窗口
    return 0;
}
