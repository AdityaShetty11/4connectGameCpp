#include "Board.h"

#include <sstream>

Board::Board() {
    grid_ = std::vector<std::vector<char> >(ROWS, std::vector<char>(COLUMNS, '.'));
}

bool Board::isColumnValid(int column) const {
    return column >= 0 && column < COLUMNS;
}

bool Board::isColumnFull(int column) const {
    return !isColumnValid(column) || grid_[0][column] != '.';
}

bool Board::isFull() const {
    for (int column = 0; column < COLUMNS; column++) {
        if (!isColumnFull(column)) {
            return false;
        }
    }

    return true;
}

bool Board::dropPiece(int column, char piece) {
    if (piece == '.' || isColumnFull(column)) {
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

bool Board::hasWinner() const {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            char cell = grid_[row][column];

            if (cell == '.') {
                continue;
            }

            if (column + 3 < COLUMNS &&
                cell == grid_[row][column + 1] &&
                cell == grid_[row][column + 2] &&
                cell == grid_[row][column + 3]) {
                return true;
            }

            if (row + 3 < ROWS &&
                cell == grid_[row + 1][column] &&
                cell == grid_[row + 2][column] &&
                cell == grid_[row + 3][column]) {
                return true;
            }

            if (row + 3 < ROWS &&
                column + 3 < COLUMNS &&
                cell == grid_[row + 1][column + 1] &&
                cell == grid_[row + 2][column + 2] &&
                cell == grid_[row + 3][column + 3]) {
                return true;
            }

            if (row + 3 < ROWS &&
                column - 3 >= 0 &&
                cell == grid_[row + 1][column - 1] &&
                cell == grid_[row + 2][column - 2] &&
                cell == grid_[row + 3][column - 3]) {
                return true;
            }
        }
    }

    return false;
}

char Board::getCell(int row, int column) const {
    return grid_[row][column];
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
