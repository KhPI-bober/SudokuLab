#pragma once

#include "sudoku_types.h"

#include "stack"

class Board;

class Solver
{
public:
    bool solve(Board& inBoard);

private:
    bool findEmptyCell(std::pair<int, int>& cell) const;
    bool trySetLegalNum(const std::pair<int, int>& cell);

private:
    Board* board = nullptr;
};
