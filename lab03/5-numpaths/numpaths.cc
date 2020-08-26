#include <iostream>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>
#include <set>

std::map<std::string, int> 
readNums(std::vector<std::string> fileNames)
{
  std::map<std::string, int> map; //empty collection
  for (auto fileName : fileNames) { //let compiler figure out fileName is string
    std::ifstream in(fileName); //open file
    if (!in) {
      std::cerr << "cannot read \"" << fileName << "\"" << std::endl;
      std::exit(1);
    }
    int i;
    while (in >>i) {
      if (map.find(fileName) == map.end())
        map[fileName] = i;
      else
        map[fileName] += i;
    }
    if (!in.eof()) {
      std::cerr << "i/o error on file \"" << fileName << "\"" << std::endl;
      std::exit(1);
    }
  } //for
  return map;
}

static void
interact(const std::map<std::string, int>& map)
{
  std::string path;
  std::cout << ">> ";
  while (std::cin >> path) {
    try {
      int sum = map.at(path);
      std::cout << path << ": " << sum << std::endl;
    }
    catch (std::out_of_range& err) {
      std::cout << path << ": " << "NOT FOUND" << std::endl;
    }
    std::cout << ">> ";
  } //while
}

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " FILE..." << std::endl;
    std::exit(1);
  }
  auto map = readNums(std::vector<std::string>(&argv[1], &argv[argc]));
  interact(map);
}

