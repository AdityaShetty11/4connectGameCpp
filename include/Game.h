#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game();

    void run();

private:
    Board board_;
    Player player1_;
    Player player2_;
    int currentPlayerNumber_;

    const Player& currentPlayer() const;
    void renderBoard() const;
    void renderTurnPrompt() const;
    int readMove() const;
    void handleTurn();
    void switchPlayer();
    bool isGameOver() const;
    void renderOutcome() const;
};

#endif
