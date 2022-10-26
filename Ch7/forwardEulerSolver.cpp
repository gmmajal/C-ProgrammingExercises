#include "forwardEulerSolver.hpp"
#include <fstream>
#include <cassert>
#include <iostream>

void ForwardEulerSolver::setPtr(double (*p_function)(double y, double t)){
    p_func=p_function;
}

double ForwardEulerSolver::RightHandSide(double y, double t){
    return p_func(y,t);
}

double ForwardEulerSolver::SolveEquation(){
    double ynew;
    double yold = initialValue;
    double t = initialTime;
    std::ofstream writeTYData("ForwEul_ty.dat");
    assert(writeTYData.is_open());
    writeTYData.setf(std::ios::scientific);
    writeTYData<<t<<" "<<yold<<"\n";
    while(t<(finalTime-stepSize)){
        ynew = yold + stepSize*RightHandSide(yold,t);
        t=t+stepSize;
	writeTYData<<t<<" "<<ynew<<"\n";
        yold = ynew;
    }
    writeTYData.close();
    return 1.5;
}
