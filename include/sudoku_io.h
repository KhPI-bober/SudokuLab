#pragma once

#include "sudoku_types.h"

#include "iosfwd"

std::istream& operator>>(std::istream& cin, Board& board);
std::ostream& operator<<(std::ostream& cout, const Board& board);

class Logger
{
public:
    static void setOutput(std::ostream& cout);
    static void info(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);
    static void log(const std::string& message, const std::string& verb);

private:
    static std::ostream* output;
};
