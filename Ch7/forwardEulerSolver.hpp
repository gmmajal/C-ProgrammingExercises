#ifndef FORWARDEULERSOLVERHEADERREF
#define FORWARDEULERSOLVERHEADERREF
#include "abstractOdeSolver.hpp"

class ForwardEulerSolver:public AbstractOdeSolver{
    public:
        double RightHandSide(double y, double t);
        double SolveEquation();
        void setPtr(double (*p_function)(double y, double t));
    private:
        double (*p_func)(double y, double t);
};
#endif
