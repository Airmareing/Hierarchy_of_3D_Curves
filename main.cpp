#include <memory>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

#include "AbstractCurve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix3D.h"
#include "OstreamOverloads.h"


using std::cout;
using std::cerr;
using std::endl;

typedef std::shared_ptr<AbstractCurve> CurvePtr;
typedef std::shared_ptr<Circle> CirclePtr;

double randDouble(double lower_bound, double upper_bound)
{
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::random_device r;
    std::default_random_engine re(r());
    
    return unif(re);
}

CurvesTypes getRandomType()
{
    std::uniform_int_distribution<int> unif(CIRCLE, HELIX);
    std::random_device r;
    std::default_random_engine re(r());

    return static_cast<CurvesTypes>(unif(re));
}

CurvePtr makeRandomCurve() {
    CurvesTypes randomType = getRandomType();

    switch (randomType){
    case CIRCLE:
        return std::make_shared<Circle>(randDouble(0, 100.0));
    case ELLIPSE:
        return std::make_shared<Ellipse>(randDouble(0, 100.0), randDouble(0, 100.0));
    case HELIX:
        return std::make_shared<Helix3D>(randDouble(0, 100.0), randDouble(-100, 100));
    }

    return CurvePtr();
}

void PrintType(CurvesTypes type) {
    switch (type) {
    case CIRCLE:
        cout << "Circle";
        break;
    case ELLIPSE:
        cout << "Ellipse";
        break;
    case HELIX:
        cout << "Helix";
        break;
    }
}

int main() {
    // 2
    std::vector<CurvePtr> firstVec(10);
    for (CurvePtr& p : firstVec) {
        p = makeRandomCurve();
    }
    
    // 3
    cout << "\tTASK 3\n\nPoints and Derivatives at t = PI/4:" << endl;
    for(const CurvePtr& p : firstVec) {
        cout << "Class: " << p->GetType() << endl;
        cout << "Point: " << p->GetPoint(M_PI/4) << endl;
        cout << "Derivative: " << p->GetDeriv(M_PI/4) << endl;
        cout << endl;
    }

    // 4
    std::vector<CirclePtr> circleVec;
    for (const CurvePtr& p : firstVec) {
        if (p->GetType() == CIRCLE) {
            try {
                circleVec.push_back(std::dynamic_pointer_cast<Circle>(p));
            } catch(const std::exception& ex) {
                cerr << ex.what();
            }
        }
    }

    // 5
    auto compare = [](const CirclePtr& a, const CirclePtr& b) {
        return *a < *b;
    };
    std::sort(circleVec.begin(), circleVec.end(), compare);

    // 6
    double summ = 0.0, buff = 0.0;
    cout << "\tTASK 5\n\nRadii:" << endl;
    for (const CirclePtr& p : circleVec) {
        buff += p->GetRadius();
        summ += buff;
        cout << "Radius: " << buff << endl;
        cout << endl;
    }
    cout << "\tTASK 6\n\nSum of radii: " << summ << endl;

    return 0;
}