#include "Player.h"

Player::Player(std::string name, char piece)
    : name_(name), piece_(piece) {
}

const std::string& Player::getName() const {
    return name_;
}

char Player::getPiece() const {
    return piece_;
}
