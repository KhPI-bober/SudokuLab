#include "sudoku_solver.h"

#include "sudoku_io.h"
#include "sudoku_types.h"

#include "fstream"
#include "format"

void sudokuSolver()
{
    std::ifstream cin("data/sudoku.in");
    std::ofstream cout("data/sudoku.out");

    Board board;

    if (!checkBoardSizes(board))
    {
        log("Board sizes incorrect. Check data in sudoku_types.h", ERROR);

        return;
    }

    if (!validateSegmentSizes())
    {
        log("Segment consts incorrect. Check data in sudoku_types.h", ERROR);

        return;
    }

    cin >> board;
    cout << board;

    if (checkBoard(board))
    {
        log("Board is Correct");
    }
    else
    {
        log("Board is Incorrect", ERROR);
    }
}

bool checkBoard(const Board& board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (
            checkRow(board, i) &&
            checkColumn(board, i) &&
            checkSegment(board, i)
        )
        {
            continue;
        }

        log("Board has mistakes", WARNING);

        return false;
    }

    return true;
}

bool checkRow(const Board& board, int rowIndex)
{
    std::array<bool, MAX_NUM> counter = {};

    int i = rowIndex;

    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        if (!checkNum(counter, board[i][j]))
        {
            log(std::format("checkRow: num {} at ({}, {}) is wrong", board[i][j], i, j), WARNING);

            return false;
        }
    }

    return true;
}

bool checkColumn(const Board& board, int colIndex)
{
    std::array<bool, MAX_NUM> counter = {};

    int j = colIndex;

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (!checkNum(counter, board[i][j]))
        {
            log(std::format("checkColumn: num {} at ({}, {}) is wrong", board[i][j], i, j), WARNING);

            return false;
        }
    }

    return true;
}

bool checkSegment(const Board& board, int segmentNum)
{
    std::array<bool, MAX_NUM> counter = {};

    int segStartRow = segmentNum / SEGS_IN_LINE * SEGS_IN_LINE;
    int segStartCol = segmentNum % SEGS_IN_LINE * SEGS_IN_LINE;

    for (int x = 0; x < SEG_SIZE; ++x)
    {
        int j = segStartCol + x;

        for (int y = 0; y < SEG_SIZE; ++y)
        {
            int i = segStartRow + y;

            if (!checkNum(counter, board[i][j]))
            {
                log(std::format("checkSegment: num {} at ({}, {}) is wrong", board[i][j], i, j), WARNING);

                return false;
            }
        }
    }

    return true;
}

bool checkBoardSizes(const Board& board)
{
    if (board.size() != BOARD_SIZE)
    {
        log("Wrong board height", WARNING);

        return false;
    }

    for (const Row& row : board)
    {
        if (row.size() != BOARD_SIZE)
        {
            log("Wrong board width", WARNING);

            return false;
        }
    }

    return true;
}

bool validateSegmentSizes()
{
    if (SEG_SIZE * SEGS_IN_LINE != BOARD_SIZE)
    {
        log("Wrong segments parameters.", WARNING);

        return false;
    }

    return true;
}

bool checkNum(std::array<bool, MAX_NUM>& counter, int num)
{
    if (num == 0)
    {
        return true;
    }

    if (num < 0 || num > MAX_NUM)
    {
        log(std::format("Num {} is not allowed.", num), WARNING);

        return false;
    }

    if (counter[num - 1])
    {
        log(std::format("Num {} used twice.", num), WARNING);

        return false;
    }

    counter[num - 1] = true;

    return true;
}

