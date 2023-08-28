#include "Circle.h"

Point Circle::GetPoint(parametr_t t) const {
    double x = cos(t) * m_rad;
    double y = sin(t) * m_rad;
    return Point(x, y);
}

Vector3D Circle::GetDeriv(parametr_t t) const {
    double dx = -m_rad * sin(t);
    double dy = m_rad * cos(t);
    return Vector3D(dx, dy);
}
