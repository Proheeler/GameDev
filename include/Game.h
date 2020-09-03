#pragma once

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
