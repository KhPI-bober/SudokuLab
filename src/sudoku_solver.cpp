#include "sudoku_solver.h"

#include "sudoku_io.h"
#include "sudoku_types.h"

#include "format"

bool Solver::solve(Board& inBoard)
{
    board = &inBoard;

    std::pair<int, int> cell;

    while (findEmptyCell(cell))
    {
        if (trySetLegalNum(cell))
        {
            continue;
        }

        Logger::warning(std::format("solve: cant set valid num into the cell ({}, {})", cell.first, cell.second));

        return false;
    }

    return true;
}

bool Solver::findEmptyCell(std::pair<int, int>& cell) const
{
    for (cell.first = 0; cell.first < board->size(); ++cell.first)
    {
        for (cell.second = 0; cell.second < board->size(); ++cell.second)
        {
            if (board->isEmptyCell(cell))
            {
                return true;
            }
        }
    }

    return false;
}

bool Solver::trySetLegalNum(const std::pair<int, int>& cell)
{
    for (int num = 1; num < board->maxNum(); ++num)
    {
        board->setNum(cell, num);

        if (board->isValid())
        {
            return true;
        }
    }

    board->clearCell(cell);

    return false;
}
