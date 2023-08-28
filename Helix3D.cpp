#include "Helix3D.h"

Point Helix3D::GetPoint(parametr_t t) const {
    double x = cos(t) * m_rad;
    double y = sin(t) * m_rad;
    double z = m_step * t / 2 / M_PI;
    return Point(x, y, z);
    return Point();
}

Vector3D Helix3D::GetDeriv(parametr_t t) const {
    double dx = -m_rad * sin(t);
    double dy = m_rad * cos(t);
    double dz = m_step / 2 / M_PI;
    return Vector3D(dx, dy, dz);
    return Vector3D();
}
