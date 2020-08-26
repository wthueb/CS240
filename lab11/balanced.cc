#include <iostream>

#include <string.h>

#include "stack.hh"


typedef struct
{
    char delim;
    int encoding;
} delim_map;

delim_map delim_encodings[] = {
    { '(', 1 }, { ')', -1 },
    { '[', 2 }, { ']', -2 },
    { '<', 3 }, { '>', -3 },
    { '{', 4 }, { '}', -4 }
};

delim_map* convert_to_delim(char c)
{
    for (unsigned i = 0; i < sizeof(delim_encodings) / sizeof(delim_map); ++i)
    {
        if (c == delim_encodings[i].delim)
            return &delim_encodings[i];
    }

    return nullptr;
}


int main(int argc, char** argv)
{
    //if ((argc - 1) % 2 != 0)
    //{
    //    std::cout << "odd number of delimiters given" << std::endl;
    //    return 1;
    //}

    if (argc < 2)
    {
        std::cout << "usage:\n\tbalanced DELIM..." << std::endl;
        return 1;
    }

    stack<delim_map> stk;

    for (int i = 1; i < argc; ++i)
    {
        char* arg = argv[i];

        if (strlen(arg) != 1)
        {
            std::cout << "argument #" << i << " is not a single character" << std::endl;
            return 1;
        }

        delim_map* dm = convert_to_delim(arg[0]);

        if (!dm)
        {
            std::cout << "invalid delimiter '" << arg[0] << "'" << std::endl;
            return 1;
        }

        if (dm->encoding > 0)
        {
            stk.push(*dm);
        }
        else
        {
            if (stk.size() == 0)
            {
                std::cout << "unbalanced at argument " << i << std::endl;
                return 1;
            }

            delim_map first = stk.pop();

            if (first.encoding != -dm->encoding)
            {
                std::cout << "unbalanced at argument " << i << std::endl;
                return 1;
            }
        }
    }

    if (stk.size() > 0)
    {
        std::cout << "unbalanced at argument " << argc - 1 << std::endl;
    }

    return 0;
}
