#include "animal.hh"

#include <iostream>

int main(int argc, char* argv[]) {
  std::ostream& out = std::cout;
  Cat fluffy("fluffy"), simba("simba");
  Dog fido("fido"), rufus("rufus");
  Cow bossy("bossy"), bessie("bessie");
  const Animal *animals[] = {
    &bessie,
    &bossy,
    &fido,
    &fluffy,
    &rufus,
    &simba,
  };
  for (auto animalP : animals) {
    out << animalP->name << " eats " << animalP->eats() << std::endl;
  }
}
