#include "sudoku_types.h"

#include "sudoku_io.h"
#include "sudoku_utils.h"

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

int Board::size() const
{
    return BOARD_SIZE;
}

int Board::maxNum() const
{
    return MAX_NUM;
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

bool Board::isEmptyCell(const std::pair<int, int>& cell) const
{
    if (!isValidCell(cell))
    {
        Logger::error(std::format("isEmptyCell: attempt to access invalid indexes ({}, {})", cell.first, cell.second));

        return false;
    }

    return data[cell.first][cell.second] == 0;
}

void Board::setNum(const std::pair<int, int>& cell, int num)
{
    if (!isValidCell(cell))
    {
        Logger::error(std::format("setNum: attempt to access invalid indexes ({}, {})", cell.first, cell.second));

        return;
    }

    if (!isValidNum(num))
    {
        Logger::error(std::format("setNum: attempt to set invalid num {}", num));

        return;
    }

    data[cell.first][cell.second] = num;
}

void Board::clearCell(const std::pair<int, int>& cell)
{
    if (!isValidCell(cell))
    {
        Logger::error(std::format("clearCell: attempt to access invalid indexes ({}, {})", cell.first, cell.second));

        return;
    }

    data[cell.first][cell.second] = 0;
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

bool Board::isValidCell(const std::pair<int, int>& cell) const
{
    return cell.first >= 0 && cell.first < BOARD_SIZE && cell.second >= 0 && cell.second < BOARD_SIZE;
}

bool Board::isValidNum(int num) const
{
    return num > 0 && num <= MAX_NUM;
}
