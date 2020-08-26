#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool brute_force_crack(const std::string&, int);
bool dictionary_crack(const std::string&, int, bool);
bool random_crack(const std::string&, int);

void print_usage(char* call)
{
    std::cout << "usage:\t" << call << " [--sorted]" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc > 2)
    {
        print_usage(argv[0]);
        return 1;
    }

    bool dict_sorted = false;

    if (argc == 2)
    {
        if (std::string(argv[1]).compare("--dict_sorted"))
        {
            print_usage(argv[0]);
            return 1;
        }

        dict_sorted = true;
    }

    auto crack_passwords = [dict_sorted](std::fstream& password_file, int max_characters)
    {
        std::string password;
        bool success = false;

        while (std::getline(password_file, password))
        {
            std::cout << "current password: " << password << std::endl;

            std::cout << "\tbrute forcing..." << std::endl;
            auto bf_start = std::chrono::high_resolution_clock::now();
            success = brute_force_crack(password, max_characters);
            if (success)
            {
                auto bf_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> bf_time = (bf_end - bf_start) * 1000;
                std::cout << "\t\tTime: " << bf_time.count() << " milliseconds" << std::endl;
            }
            else
            {
                std::cout << "\t\tdid not crack" << std::endl;
            }

            std::cout << "\tdictionary cracking..." << std::endl;
            auto dict_start = std::chrono::high_resolution_clock::now();
            success = dictionary_crack(password, max_characters, dict_sorted);
            if (success)
            {
                auto dict_end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> dict_time = (dict_end - dict_start) * 1000;
                std::cout << "\t\tTime: " << dict_time.count() << " milliseconds" << std::endl;
            }
            else
            {
                std::cout << "\t\tdid not crack" << std::endl;
            }

            std::cout << "\trandom cracking..." << std::endl;
            auto rand_start =  std::chrono::high_resolution_clock::now();
            success = random_crack(password, max_characters);
            if (success)
            {
                auto rand_end =  std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> rand_time = (rand_end - rand_start) * 1000;
                std::cout << "\t\tTime: " << rand_time.count() << " milliseconds" << std::endl;
            }
            else
            {
                std::cout << "\t\tdid not crack" << std::endl;
            }
        }
    };

    int max_characters = 5;

    std::cout << "Testing random passwords with maximum length of 5." << std::endl;
    std::fstream random_passwords("test_passwords/random_passwords.txt");
    crack_passwords(random_passwords, max_characters);

    std::cout << "Testing common passwords with maximum length of 5." << std::endl;
    std::fstream common_passwords("test_passwords/common_passwords.txt");
    crack_passwords(common_passwords, max_characters);

    return 0;
}

