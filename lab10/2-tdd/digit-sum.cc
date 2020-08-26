#include <cctype>

#include "digit-sum.hh"

int
digitSum(const char* str)
{
    int acc = 0;
    bool want_digit = true;

    for (const char* p = str; *p; ++p)
    {
        const char c = *p;

        if (isdigit(c))
        {
            if (want_digit)
            {
                acc += c - '0';
                want_digit = false;
            }
            else
                break;
        }
        else if (c == '+')
        {
            if (want_digit)
                break;

            want_digit = true;
        }
        else if (isspace(c))
            continue;
        else
            break;
    }

    return acc;
}
