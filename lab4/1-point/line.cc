#include "line.hh"

#include <string>
#include <sstream>

double Line::length() const
{
  return this->start.distance(this->end);
}

std::string Line::toString() const
{
  std::stringstream s;

  s << this->start.toString() << " -- " << this->end.toString();

  return s.str();
}
