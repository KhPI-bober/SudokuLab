#include "sudoku_io.h"
#include "sudoku_solver.h"
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

    if (board.isValid())
    {
        Logger::info("Start board is correct");
    }
    else
    {
        Logger::error("Start board has problems");

        return 0;
    }

    Solver solver;

    if (solver.solve(board))
    {
        Logger::info("Board solved");
    }
    else
    {
        Logger::info("Board is not solved");
    }

    cout << board;

    return 0;
}
