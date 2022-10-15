#include <iostream>

void printInteger(int *p){
    std::cout<<"The value of the integer is "<<*p<<"\n";
}

int main(int argc,char* argv[]){
    int x = 2;
    printInteger(&x);
    return 0;
}