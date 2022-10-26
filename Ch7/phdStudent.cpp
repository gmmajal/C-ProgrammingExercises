#include "phdStudent.hpp"
#include <cassert>
//Uncomment in case you want to include the console output
//#include <iostream>


PhdStudent::PhdStudent(){
    name = "John Doe";
    engagement = "full-time";
    tuitionFee = 0.0;
}

PhdStudent::PhdStudent(std::string n, std::string e){
    assert(e=="part-time" || e=="full-time");
    name = n;
    engagement = e;
    tuitionFee = 0.0;
}

double PhdStudent::MoneyOwed(){
    //uncomment in order to ensure that this method is called
    //std::cout<< "<value being taken from PhdStudent class>\n";
    return 0.0;
}
