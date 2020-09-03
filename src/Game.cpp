#include <Game.h>

Game::Game(/* args */)
{
}

Game::~Game()
{
}

void Game::init() { m_bRunning = true; }

void Game::render() {}

void Game::update() {}

void Game::handleEvents() {}

void Game::clean() {}

bool Game::running() { return m_bRunning; }
