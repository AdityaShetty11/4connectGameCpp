#include "Game.h"

#include <iostream>

Game::Game()
    : player1_("Player 1", 'R'), player2_("Player 2", 'Y'), currentPlayerNumber_(1) {
}

void Game::run() {
    renderBoard();
}

void Game::renderBoard() const {
    std::cout << '\n' << board_.toString() << '\n';
}

void Game::handleTurn() {
}

void Game::switchPlayer() {
    if (currentPlayerNumber_ == 1) {
        currentPlayerNumber_ = 2;
    } else {
        currentPlayerNumber_ = 1;
    }
}
