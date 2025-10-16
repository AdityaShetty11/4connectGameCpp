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

    void renderBoard() const;
    void handleTurn();
    void switchPlayer();
};

#endif
