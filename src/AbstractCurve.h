#ifndef ABSTRACT_CURVE
#define ABSTRACT_CURVE

#include <cmath>

#include "Point.h"
#include "Vector3D.h"

typedef double parametr_t;

enum CurvesTypes {
    CIRCLE,
    ELLIPSE,
    HELIX
};

class AbstractCurve {
public:
    virtual ~AbstractCurve() {}

    virtual CurvesTypes GetType() const = 0;
    virtual Point GetPoint(parametr_t t) const = 0;
    virtual Vector3D GetDeriv(parametr_t t) const = 0;
};

#endif // ABSTRACT_CURVE