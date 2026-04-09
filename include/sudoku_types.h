#pragma once

#include "sudoku_consts.h"

#include "iosfwd"

class Board
{
public:
    void read(std::istream& cin);
    void print(std::ostream& cout, char emptyCell = '-') const;

    bool isValid() const;

private:
    bool isValidRow(int rowIndex) const;
    bool isValidCol(int colIndex) const;
    bool isValidSeg(int segIndex) const;

private:
    int data[BOARD_SIZE][BOARD_SIZE];
};
