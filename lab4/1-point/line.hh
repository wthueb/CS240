#ifndef LINE_HH_
#define LINE_HH_

#include <string>

#include "point.hh"

struct Line {
  const Point start, end;

  Line(Point p1={0., 0.}, Point p2={0., 0.}) : start(p1), end(p2) { }

  double length() const;

  std::string toString() const;
};

#endif
