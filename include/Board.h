#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

class Board {
public:
    static const int ROWS = 6;
    static const int COLUMNS = 7;

    Board();

    bool isColumnValid(int column) const;
    bool dropPiece(int column, char piece);
    std::string toString() const;

private:
    std::vector<std::vector<char> > grid_;
};

#endif
