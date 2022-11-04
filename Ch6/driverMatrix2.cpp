#include "Matrix2.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    Matrix2 m;
    std::cout<<"Testing default constructor with matrix m\n";
    std::cout<<m;
    
    Matrix2 m1 (1.0,2.0,2.0,4.0);
    std::cout<<"Printing matrix m1\n";
    std::cout<<m1;
    
    m=m1;
    std::cout<<"Testing assign operator with matrix m=m1\n";
    std::cout<<m;

    std::cout<<"The determinant of the matrix m is "<<m.calcDet()<<"\n";

    Matrix2 m2(2.0,0.0,0.0,4.0);
    std::cout<<"Printing matrix m2\n";
    std::cout<<m2;
    
    Matrix2 minv;
    minv = m2.inverse();
    std::cout<<"Testing calculation of matrix inverse for matrix m2\n";
    std::cout<<minv;

    Matrix2 m3;
    m3 = -m1;
    std::cout<<"Testing unary subtraction operation with m3 = -m1 \n";
    std::cout<<m3;
    
    Matrix2 m4;
    m4 = minv + m3;
    std::cout<<"Testing binary addition operation with m4 = minv + m3 \n";
    std::cout<<m4;
    
    Matrix2 m5;
    m5 = minv - m4;
    std::cout<<"Testing binary subtraction operation with m5 = minv - m4\n";
    std::cout<<m5;

    Matrix2 m6;
    m6 = m1.scalarMult(0.5);
    std::cout<<"Testing scalar multiplication operation with m6 = 0.5*m1\n";
    std::cout<<m6;

    return 0;
}