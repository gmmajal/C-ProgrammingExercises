#include <iostream>

int main(int argc, char *argv[]){
    std::string firstName, familyName;

    std::cout<<"After typing in the requested item please press the return key to continue\n";
    std::cout<<"Please enter your first name: ";
    std::getline(std::cin,firstName);
    std::cout<<"Please enter your family name: ";
    std::getline(std::cin,familyName);
    std::cout<<"The user's full name is: "<<firstName<<" "<<familyName;
    return 0;
}