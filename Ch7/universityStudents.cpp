#include <iostream>
#include "student.hpp"
#include "graduateStudent.hpp"
#include "phdStudent.hpp"


int main(int argc, char* argv[]){
    Student* p_stud1 = new Student;
    Student* p_stud2 = new Student("James Knox",22.1,13.5);
    Student* p_stud3 = new GraduateStudent;
    Student* p_stud4 = new GraduateStudent("Theta Beta","full-time",11.5);
    Student* p_stud5 = new PhdStudent;
    Student* p_stud6 = new PhdStudent("Xi Phi","part-time");
    
    

    //Testing the virtual function for the different classes.
    
    std::cout<<"Student 1 is named "<<p_stud1->name<<". The money owed by Student 1 is: "<<p_stud1->MoneyOwed()<<"\n";
    std::cout<<"Student 2 is named "<<p_stud2->name<<". The money owed by Student 2 is: "<<p_stud2->MoneyOwed()<<"\n";
    std::cout<<"Student 3 is named "<<p_stud3->name<<". The money owed by Student 3 is: "<<p_stud3->MoneyOwed()<<"\n";
    std::cout<<"Student 4 is named "<<p_stud4->name<<". The money owed by Student 4 is: "<<p_stud4->MoneyOwed()<<"\n";
    std::cout<<"Student 5 is named "<<p_stud5->name<<". The money owed by Student 5 is: "<<p_stud5->MoneyOwed()<<"\n";
    std::cout<<"Student 6 is named "<<p_stud6->name<<". The money owed by Student 6 is: "<<p_stud6->MoneyOwed()<<"\n";

    delete p_stud1;
    delete p_stud2;
    delete p_stud3;
    delete p_stud4;
    delete p_stud5;
    delete p_stud6;
    return 0;
}
