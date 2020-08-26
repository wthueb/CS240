#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

bool dictionary_crack(const std::string& password, int max_characters, bool sorted)
{
    // we don't want to load this into RAM since it can be huge
    std::ifstream dictionary_file("password_dictionary.txt");

    std::string attempt;

    while (std::getline(dictionary_file, attempt))
    {
        if (attempt.length() > (size_t)max_characters)
        {
            if (sorted)
                return false;

            continue;
        }

        if (!password.compare(attempt))
        {
            return true;
        }
    }

    return false;
}
