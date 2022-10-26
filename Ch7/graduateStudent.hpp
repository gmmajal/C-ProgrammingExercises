#ifndef GRADUATESTUDENTHEADERDEF
#define GRADUATESTUDENTHEADERDEF

#include "student.hpp"

class GraduateStudent: public Student{
    public:
        GraduateStudent();
        GraduateStudent(std::string n, std::string e, double f);
        double MoneyOwed();
        std::string engagement;
    private:
        double libraryFine;
};

#endif