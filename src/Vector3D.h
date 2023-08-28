#ifndef VECTOR_3D_H
#define VECTOR_3D_H

class Vector3D {
public:
    Vector3D() = default;
    Vector3D(double x, double y, double z = 0.0)
        : m_x(x), m_y(y), m_z(z) {}
    
    double x() const{
        return m_x;
    }
    double y() const{
        return m_y;
    }
    double z() const{
        return m_z;
    }
    
private:
    double m_x = 0.0;
    double m_y = 0.0;
    double m_z = 0.0;
};

#endif // VECTOR_3D_H