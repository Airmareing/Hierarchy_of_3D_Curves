#ifndef OSTREAM_OVERLOADS
#define OSTREAM_OVERLOADS

#include <sstream>

#include "Point.h"
#include "Vector3D.h"

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' 
       << p.x()
       <<", "
       << p.y()
       <<", "
       << p.z()
       << ')';
    return os;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << '{' 
       << v.x()
       <<", "
       << v.y()
       <<", "
       << v.z()
       << '}';
    return os;
}

#endif // OSTREAM_OVERLOADS