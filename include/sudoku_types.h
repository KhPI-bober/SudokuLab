#pragma once

#include "sudoku_consts.h"

#include "iosfwd"

class Board
{
public:
    void read(std::istream& cin);
    void print(std::ostream& cout, char emptyCell = '-') const;

    int size() const;
    int maxNum() const;

    bool isValid() const;

    bool isEmptyCell(const std::pair<int, int>& cell) const;
    void setNum(const std::pair<int, int>& cell, int num);
    void clearCell(const std::pair<int, int>& cell);

private:
    bool isValidRow(int rowIndex) const;
    bool isValidCol(int colIndex) const;
    bool isValidSeg(int segIndex) const;

    bool isValidCell(const std::pair<int, int>& cell) const;
    bool isValidNum(int num) const;

private:
    int data[BOARD_SIZE][BOARD_SIZE];
};
