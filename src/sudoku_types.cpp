#include "sudoku_types.h"

#include "sudoku_utils.h"
#include "sudoku_io.h"

#include "format"
#include "istream"
#include "ostream"

void Board::read(std::istream& cin)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            char ch;
            cin >> ch;
            data[i][j] = Utils::interpretCharacter(ch);
        }
    }
}

void Board::print(std::ostream& cout, char emptyCell) const
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (data[i][j] == 0)
            {
                cout << emptyCell;
            }
            else
            {
                cout << data[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}

bool Board::isValid() const
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (!isValidRow(i) || !isValidCol(i) || !isValidSeg(i))
        {
            return false;
        }
    }

    return true;
}

bool Board::isValidRow(int rowIndex) const
{
    bool counter[MAX_NUM] = {};

    int i = rowIndex;

    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        int num = data[i][j];

        if  (num == 0)
        {
            continue;
        }

        if (counter[num - 1])
        {
            Logger::warning(std::format("checkRow: num {} at ({}, {}) is wrong", num, i, j));

            return false;
        }

        counter[num - 1] = true;
    }

    return true;
}

bool Board::isValidCol(int colIndex) const
{
    bool counter[MAX_NUM] = {};

    int j = colIndex;

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        int num = data[i][j];

        if  (num == 0)
        {
            continue;
        }

        if (counter[num - 1])
        {
            Logger::warning(std::format("checkColumn: num {} at ({}, {}) is wrong", num, i, j));

            return false;
        }

        counter[num - 1] = true;
    }

    return true;
}

bool Board::isValidSeg(int segIndex) const
{
    bool counter[MAX_NUM] = {};

    int segStartRow = segIndex / SEGS_IN_LINE * SEGS_IN_LINE;
    int segStartCol = segIndex % SEGS_IN_LINE * SEGS_IN_LINE;

    for (int x = 0; x < SEG_SIZE; ++x)
    {
        int j = segStartCol + x;

        for (int y = 0; y < SEG_SIZE; ++y)
        {
            int i = segStartRow + y;

            int num = data[i][j];

            if  (num == 0)
            {
                continue;
            }

            if (counter[num - 1])
            {
                Logger::warning(std::format("checkSegment: num {} at ({}, {}) is wrong", num, i, j));

                return false;
            }

            counter[num - 1] = true;
        }
    }

    return true;
}
