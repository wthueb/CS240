// ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...
// MAX_N_OUT: A positive integer specifying the maximum number of words to be output. 
// MIN_WORD_LEN: A positive integer specifying the minimum length of words to be output. 
// MAX_WORD_LEN: A positive integer specifying the maximum length of words to be output.
//               This must be greater than or equal to MIN_WORD_LEN.
// FILE...: The names of one-or-more files which will be the source of the words. 

#include <algorithm> // std::remove_if, std::transform
#include <cctype> // std::isalpha, std::isdigit
#include <fstream>
#include <iostream>
#include <locale> // std::tolower
#include <string>
#include <unordered_map>
#include <vector>

void clean_string(std::string& s)
{
    for (int i = 0; i < (int)s.length(); i++)
    {
        if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z'))
        {
            s.erase(i, 1);
            i--;
        }

        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
    }
}

int main(int argc, char** argv)
{
    if (argc < 5)
    {
        std::cerr << "not enough arguments. usage:\n" << 
                     "\t./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...\n";

        return 1;
    }

    auto check_arg = [](const std::string& name, const std::string& arg) -> int
    {
        for (char c : arg)
        {
            if (!std::isdigit(c))
            {
                std::cout << "invalid value for " << name << ": " << arg << '\n';

                return -1;
            }
        }

        int val = std::stoi(arg);

        if (val <= 0)
        {
            std::cout << "invalid value for " << name << ": " << arg << '\n';

            return -1;
        }

        return val;
    };

    int max_n_out, min_word_len, max_word_len;

    if ((max_n_out = check_arg("MAX_N_OUT", argv[1])) == -1)
        return 1;

    if ((min_word_len = check_arg("MIN_WORD_LEN", argv[2])) == -1)
        return 1;

    if ((max_word_len = check_arg("MAX_WORD_LEN", argv[3])) == -1)
        return 1;

    if (max_word_len < min_word_len)
    {
        std::cerr << "MAX_WORD_LEN has to be >= MIN_WORD_LEN\n";

        return 1;
    }

    std::vector<std::string> files(&argv[4], &argv[argc]);

    std::unordered_map<std::string, int> word_counts_map;

    for (std::string path : files)
    {
        std::ifstream file(path);

        if (!file)
        {
            std::cerr << "unable to open file " << path << '\n';

            return 1;
        }

        std::string word;

        while (file >> word)
        {
            // get rid of non-letters
            word.erase(std::remove_if(word.begin(), word.end(),
                       [](const char& c) -> bool { return !std::isalpha(c); }), word.end());

            // convert to lowercase
            std::transform(word.begin(), word.end(), word.begin(),
                           [](const char& c) -> char { return std::tolower(c); });

            // if it is ascii encoded we can use this function instead of the two lines above
            //clean_string(word);

            int len = word.length();

            if (len >= min_word_len && len <= max_word_len)
                ++word_counts_map[word];
        }

        if (!file.eof())
        {
            std::cerr << "i/o error on file " << path << '\n';

            return 1;
        }
    }

    typedef std::pair<std::string, int> wc_pair;

    std::vector<wc_pair> counts(word_counts_map.begin(), word_counts_map.end());

    std::sort(counts.begin(), counts.end(), [](const wc_pair& a, const wc_pair& b) -> bool
    {
        if (a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    });

    for (int i = 0; i < std::min<int>(max_n_out, counts.size()); ++i)
        std::cout << counts[i].first << ": " << counts[i].second << '\n';

    return 0;
}
