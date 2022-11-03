#include <iostream>
#include "DoubleVector.hpp"

int main(int argc, char* argv[]){
    DoubleVector<8>v;
    v[0] = 1e-3;
    v[1] = -1e-6;  //try -1e-3, the program assertion
    v[2] = 0.4;
    v[3] = 1.0;
    v[4] = 0.0; //try (1.0+1e-3), the program throws assertion
    v[5] = (1.0+1e-6);
    v[6] = (1.0+1e-10);
    v[7] = (-1e-10);
    std::cout<<"v[0]= "<<v[0]<<"\n";
    std::cout<<"v[1]= "<<v[1]<<"\n";
    std::cout<<"v[2]= "<<v[2]<<"\n";
    std::cout<<"v[3]= "<<v[3]<<"\n";
    std::cout<<"v[4]= "<<v[4]<<"\n";
    std::cout<<"v[5]= "<<v[5]<<"\n";
    std::cout<<"v[6]= "<<v[6]<<"\n";
    std::cout<<"v[7]= "<<v[7]<<"\n";
    return 0;
}