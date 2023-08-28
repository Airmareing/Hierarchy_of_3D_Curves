#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "AbstractCurve.h"

class Ellipse : public AbstractCurve {
public:
    Ellipse() = default;
    Ellipse(double radius_x, double radius_y)
        : m_radx(radius_x), m_rady(radius_y) {}

    virtual Point GetPoint(parametr_t t) const final;
    virtual Vector3D GetDeriv(parametr_t t) const final;

    virtual CurvesTypes GetType() const final {
        return ELLIPSE;
    }

    double GetRadiusX() const {
        return m_radx;
    }
    double GetRadiusY() const {
        return m_rady;
    }

private:
    double m_radx = 0.0;
    double m_rady = 0.0;
};

#endif // ELLIPSE_H