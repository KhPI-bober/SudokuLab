#pragma once

#include "sudoku_types.h"

void sudokuSolver();

bool checkBoard(const Board& board);

bool checkRow(const Board& board, int rowIndex);
bool checkColumn(const Board& board, int colIndex);
bool checkSegment(const Board& board, int segmentNum);

bool checkBoardSizes(const Board& board);
bool validateSegmentSizes();

bool checkNum(std::array<bool, MAX_NUM>& counter, int num);
