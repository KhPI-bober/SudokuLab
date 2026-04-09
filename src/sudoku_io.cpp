#include "sudoku_io.h"

#include "format"
#include "iostream"

std::istream& operator>>(std::istream& cin, Board& board)
{
    board.read(cin);

    return cin;
}

std::ostream& operator<<(std::ostream& cout, const Board& board)
{
    board.print(cout);

    return cout;
}

std::ostream* Logger::output = nullptr;

void Logger::setOutput(std::ostream& cout)
{
    output = &cout;
}

void Logger::info(const std::string& message)
{
    log(message, "INFO");
}

void Logger::warning(const std::string& message)
{
    log(message, "WARNING");
}

void Logger::error(const std::string& message)
{
    log(message, "ERROR");
}

void Logger::log(const std::string& message, const std::string& verb)
{
    std::ostream& cout = output == nullptr ? std::cout : *output;

    cout << std::format("[{}] {}\n", verb, message);
}
