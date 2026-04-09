#include "sudoku_utils.h"

#include "sudoku_consts.h"

int Utils::interpretCharacter(char ch)
{
    int num = 0;

    if (ch >= '0' && ch <= '9')
    {
        num = ch - '0';
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        num = ch - 'a' + 10;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        num = ch - 'A' + 10;
    }

    return num > MAX_NUM ? 0 : num;
}
