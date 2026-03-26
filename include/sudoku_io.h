#pragma once

#include "sudoku_types.h"

#include "iosfwd"

std::istream& operator>>(std::istream& cin, Board& board);
std::ostream& operator<<(std::ostream& cout, const Board& board);

void log(const std::string& message, const std::string& verb = INFO);
