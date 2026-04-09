#include "sudoku_io.h"
#include "sudoku_types.h"

#include "fstream"

int main()
{
    std::ifstream cin("data/sudoku.in");
    std::ofstream cout("data/sudoku.out");

    std::ofstream logOut("sudoku.log");
    Logger::setOutput(logOut);

    Board board;

    cin >> board;
    cout << board;

    if (board.isValid())
    {
        Logger::info("Board is ok");
    }
    else
    {
        Logger::error("Board has problems");
    }

    return 0;
}
