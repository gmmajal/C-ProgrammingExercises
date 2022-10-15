#include <iostream>

int main(int argc, char* argv[]){
    int i1=4, i2=5;
    int tmp;
    int* p_1;
    int* p_2;

    p_1=&i1;
    p_2=&i2;

    std::cout<<"Original Values\n";
    std::cout<<"i1 has the value: "<<i1<<"\n";
    std::cout<<"i2 has the value: "<<i2<<"\n";

    tmp  = *p_1;
    *p_1 = *p_2;
    *p_2 = tmp;

    std::cout<<"Swapped Values\n";
    std::cout<<"i1 has the value: "<<i1<<"\n";
    std::cout<<"i2 has the value: "<<i2<<"\n";

    return 0;
}