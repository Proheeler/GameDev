#pragma once

enum GameState
{
MENU = 0,
PLAY = 1,
GAMEOVER = 2
};


class Game
{
private:
    /* data */
public:
    Game(/* args */);
    ~Game();
    void init();
    void render();
    void update();
    void handleEvents();
    void clean();

    // a function to access the private running variable
    bool running();

private:
    bool m_bRunning;
};
