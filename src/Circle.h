#ifndef CIRCLE_H
#define CIRCLE_H

#include "AbstractCurve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix3D.h"

class Circle : public AbstractCurve {
public:
    Circle() = default;
    Circle(double radius)
        : m_rad(radius) {}

    virtual Point GetPoint(parametr_t t) const final;
    virtual Vector3D GetDeriv(parametr_t t) const final;

    virtual CurvesTypes GetType() const final {
        return CIRCLE;
    }

    double GetRadius() const {
        return m_rad;
    }

    bool operator<(const Circle& other) {
        return m_rad < other.GetRadius();
    }

private:
    double m_rad = 0.0;
};

#endif // CIRCLE_H