#include "student.hpp"
#include <cassert>

Student::Student(){
    name = "John Doe";
    libraryFine = 0.0;
    tuitionFee = 0.0;
}

Student::Student(std::string n, double f, double t){
    assert( (f>=0.0) && (t>=0.0));
    name = n;
    libraryFine = f;
    tuitionFee = t;
}

double Student::MoneyOwed(){
    return libraryFine + tuitionFee;
}

void Student::SetLibraryFine(double f){
    assert(f>=0.0);
    libraryFine = f;
}
        
double Student::GetLibraryFine(){
    return libraryFine;
}