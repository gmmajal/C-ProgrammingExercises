#include "rungeKuttaSolver.hpp"
#include <fstream>
#include <cassert>
#include <iostream>

double RungeKuttaSolver::RightHandSide(double y, double t){
	return p_func(y,t);
}

void RungeKuttaSolver::setPtr(double (*p_function)(double y, double t)){
	p_func = p_function;
}

double RungeKuttaSolver::SolveEquation(){
	double t = initialTime;
	double yold = initialValue;
	std::ofstream writeTYData("RK4_ty.dat");
	assert(writeTYData.is_open());
	writeTYData.setf(std::ios::scientific);
	writeTYData<<t<<" "<<yold<<"\n";
	while(t<(finalTime-stepSize)){
		double k1 = stepSize*RightHandSide(yold,t);
		double k2 = stepSize*RightHandSide(yold + (0.5*k1), t + (0.5*stepSize));
		double k3 = stepSize*RightHandSide(yold + (0.5*k2), t + (0.5*stepSize));
		double k4 = stepSize*RightHandSide(yold + k3, t + stepSize);
		double y = yold + (k1+ (2*k2)+(2*k3)+k4)/6.0;
		t = t + stepSize;
		writeTYData<<t<<" "<<y<<"\n";
		yold = y;
	}
	writeTYData.close();
	return 1.5;
}

