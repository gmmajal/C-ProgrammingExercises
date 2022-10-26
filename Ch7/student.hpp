#ifndef STUDENTHEADERDEF
#define STUDENTHEADERDEF
#include <string>

class Student{
    public:
        Student();
        Student(std::string n, double f, double t);
        virtual double MoneyOwed();
        void SetLibraryFine(double f);
        double GetLibraryFine();
        std::string name;
        double tuitionFee;
    private:
        double libraryFine;
};

#endif