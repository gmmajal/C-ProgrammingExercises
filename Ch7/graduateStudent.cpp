#include "graduateStudent.hpp"
#include <cassert>

GraduateStudent::GraduateStudent(){
    name = "John Doe";
    engagement = "part-time";
    libraryFine = 0.0;
    tuitionFee = 0.0;
}

GraduateStudent::GraduateStudent(std::string n, std::string e, double f){
    assert(e=="part-time" || e=="full-time");
    assert(f>=0.0);
    name = n;
    engagement = e;
    libraryFine = f;
    tuitionFee = 0.0;
}

double GraduateStudent::MoneyOwed(){
    return libraryFine;
}
