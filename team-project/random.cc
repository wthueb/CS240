#include <iostream>
#include <string>
#include <cstdlib>

bool random_crack(const std::string& password, int max_characters)
{
	while (true)
	{
		int num_chars = rand() % max_characters + 1;
		
		std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

		std::string maybe;
		for (int i = 0; i < num_chars; ++i)
		{
			char random_char = chars[rand() % chars.length()];
			maybe += random_char;
		}
		if (maybe == password)
			return true;

	}

	return false;
}
