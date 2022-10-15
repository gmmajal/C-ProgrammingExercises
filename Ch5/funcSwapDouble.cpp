#include <iostream>

void swap_Ref(double &a , double &b){
    double temp;
    temp=a;
    a=b;
    b=temp;
}

void swap_Ptr(double* p_1, double* p_2){
    double temp;
    temp = *p_1;
    *p_1 = *p_2;
    *p_2 = temp;
}

int main(int argc, char* argv[]){
    double d1 = 1.5;
    double d2 = 4.8;
    std::cout<<"The doubles have the value: "<<d1<<", "<<d2<<"\n";
    std::cout<<"Applying swap by reference\n";
    swap_Ref(d1,d2);
    std::cout<<"The doubles have the value: "<<d1<<", "<<d2<<"\n";
    std::cout<<"Applying swap by pointer\n";
    swap_Ptr(&d1,&d2);
    std::cout<<"The doubles have the value: "<<d1<<", "<<d2<<"\n";
    return 0;
}