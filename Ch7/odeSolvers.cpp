#include "abstractOdeSolver.hpp"
#include "forwardEulerSolver.hpp"
#include "rungeKuttaSolver.hpp"
#include <iostream>
#include <cmath>

double myRHS(double y, double t);

int main(int argc, char* argv[]){
    double (*p_func)(double y, double t);
    p_func = &myRHS;

    double y0 = 2.0;
    double t0 = 0.0;double t1 = 1.0;
    double h = 0.1;

    ForwardEulerSolver solv;
    solv.SetInitialValue(y0);
    solv.SetTimeInterval(t0,t1);
    solv.SetStepSize(h);
    solv.setPtr(p_func);

    double flagEuler = solv.SolveEquation();
    if(fabs(flagEuler-1.5)<1e-10){
        std::cout<<"The differential equation has been solved using Forward Euler\n";
    }else{
        std::cout<<"Forward Euler solver failed\n";
    }
    
    RungeKuttaSolver rk4Solv;
    rk4Solv.SetInitialValue(y0);
    rk4Solv.SetTimeInterval(t0,t1);
    rk4Solv.SetStepSize(h);
    rk4Solv.setPtr(p_func);
    double flagRK4 = rk4Solv.SolveEquation();
    if(fabs(flagRK4 - 1.5)<1e-10){
	    std::cout<<"The differential equation has been solved using RK4\n";
    }else{
	    std::cout<<"RK4 solver failed\n";
    }
}

double myRHS(double y, double t){
    return 1.0+t;
}
