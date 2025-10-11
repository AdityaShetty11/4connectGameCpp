#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(std::string name, char piece);

    const std::string& getName() const;
    char getPiece() const;

private:
    std::string name_;
    char piece_;
};

#endif
