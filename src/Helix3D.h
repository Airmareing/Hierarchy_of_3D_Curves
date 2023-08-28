#ifndef HELIX_3D_H
#define HELIX_3D_H

#include "AbstractCurve.h"

class Helix3D : public AbstractCurve {
public:
    Helix3D() = default;
    Helix3D(double radius, double step)
        : m_rad(radius), m_step(step) {}

    virtual Point GetPoint(parametr_t t) const final;
    virtual Vector3D GetDeriv(parametr_t t) const final;

    virtual CurvesTypes GetType() const final {
        return HELIX;
    }

    double GetRadius() const {
        return m_rad;
    }
    double GetStep() const {
        return m_step;
    }

private:
    double m_rad = 0.0;
    double m_step = 0.0;
};

#endif // HELIX_3D_H