#include "sudoku_io.h"

#include "iostream"

std::istream& operator>>(std::istream& cin, Board& board)
{
    for (Row& row : board)
    {
        for (int& el : row)
        {
            char ch;
            cin >> ch;
            if (ch < '0' || ch > '9')
            {
                ch = '0';
            }
            el = ch - '0';
        }
    }

    return cin;
}

std::ostream& operator<<(std::ostream& cout, const Board& board)
{
    for (const Row& row : board)
    {
        for (int el : row)
        {
            if (el == 0)
            {
                cout << "- ";
            }
            else
            {
                cout << el << " ";
            }
        }
        cout << "\n";
    }

    return cout;
}

void log(const std::string& message, const std::string& verb)
{
    std::string logStr =
        "[" +
        verb +
        "] " +
        message
    ;

    std::cout << logStr << "\n";
}
