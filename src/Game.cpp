#include "Game.h"

#include <iostream>

Game::Game()
    : player1_("Player 1", 'R'), player2_("Player 2", 'Y'), currentPlayerNumber_(1) {
}

const Player& Game::currentPlayer() const {
    if (currentPlayerNumber_ == 1) {
        return player1_;
    }

    return player2_;
}

void Game::run() {
    while (!board_.isFull()) {
        renderBoard();
        handleTurn();
        switchPlayer();
    }

    renderBoard();
}

void Game::renderBoard() const {
    std::cout << '\n' << board_.toString() << '\n';
}

void Game::renderTurnPrompt() const {
    std::cout << currentPlayer().getName() << ", choose a column (1-7): ";
}

int Game::readMove() const {
    int input{0};

    if (!(std::cin >> input)) {
        return -1;
    }

    return input;
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

bool Game::isGameOver() const {
    return board_.hasWinner() || board_.isFull();
}

void Game::renderOutcome() const {
    if (board_.hasWinner()) {
        std::cout << currentPlayer().getName() << " wins!\n";
        return;
    }

    std::cout << "It's a draw!\n";
}
