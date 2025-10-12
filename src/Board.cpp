#include "Board.h"

#include <sstream>

Board::Board() {
    grid_ = std::vector<std::vector<char> >(ROWS, std::vector<char>(COLUMNS, '.'));
}

bool Board::isColumnValid(int column) const {
    return column >= 0 && column < COLUMNS;
}

bool Board::dropPiece(int column, char piece) {
    if (piece == '.' || !isColumnValid(column)) {
        return false;
    }

    for (int row = ROWS - 1; row >= 0; row--) {
        if (grid_[row][column] == '.') {
            grid_[row][column] = piece;
            return true;
        }
    }

    return false;
}

std::string Board::toString() const {
    std::ostringstream output;

    for (int row = 0; row < ROWS; row++) {
        output << '|';
        for (int column = 0; column < COLUMNS; column++) {
            output << grid_[row][column] << ' ';
        }
        output << "|\n";
    }

    output << " 1 2 3 4 5 6 7\n";
    return output.str();
}
