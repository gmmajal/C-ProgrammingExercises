#ifndef PHDSTUDENTHEADERREF
#define PHDSTUDENTHEADERREF

#include "graduateStudent.hpp"

class PhdStudent:public GraduateStudent{
    public:
        PhdStudent();
        PhdStudent(std::string n, std::string e);
        double MoneyOwed();
};

#endif
