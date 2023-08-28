#include "Ellipse.h"

Point Ellipse::GetPoint(parametr_t t) const {
    double x = m_radx*cos(t);
    double y = m_rady*sin(t);
    return Point(x, y);
}

Vector3D Ellipse::GetDeriv(parametr_t t) const {
    double dx = -m_radx * sin(t);
    double dy = m_rady * cos(t);
    return Vector3D(dx, dy);
}
