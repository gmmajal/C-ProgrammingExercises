#include "Matrix2.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    Matrix2 m;
    std::cout<<"Testing default constructor\n";
    std::cout<<"a11= "<<m.getElem11()<<"\n";
    std::cout<<"a22= "<<m.getElem12()<<"\n";
    std::cout<<"a21= "<<m.getElem21()<<"\n";
    std::cout<<"a22= "<<m.getElem22()<<"\n";
    
    Matrix2 m1 (1.0,2.0,2.0,4.0);
    m=m1;
    std::cout<<"Testing assign operator with matrix m\n";
    std::cout<<"a11= "<<m.getElem11()<<"\n";
    std::cout<<"a22= "<<m.getElem12()<<"\n";
    std::cout<<"a21= "<<m.getElem21()<<"\n";
    std::cout<<"a22= "<<m.getElem22()<<"\n";

    std::cout<<"The determinant of the matrix is "<<m.calcDet()<<"\n";

    Matrix2 m2(2.0,0.0,0.0,4.0);

    Matrix2 minv;
    minv = m2.inverse();
    std::cout<<"Testing calculation of matrix inverse for matrix m2\n";
    std::cout<<"a11= "<<minv.getElem11()<<"\n";
    std::cout<<"a22= "<<minv.getElem12()<<"\n";
    std::cout<<"a21= "<<minv.getElem21()<<"\n";
    std::cout<<"a22= "<<minv.getElem22()<<"\n";

    Matrix2 m3;
    m3 = -m1;
    std::cout<<"Testing unary subtraction operation\n";
    std::cout<<"a11= "<<m3.getElem11()<<"\n";
    std::cout<<"a22= "<<m3.getElem12()<<"\n";
    std::cout<<"a21= "<<m3.getElem21()<<"\n";
    std::cout<<"a22= "<<m3.getElem22()<<"\n";
    
    Matrix2 m4;
    m4 = minv + m3;
    std::cout<<"Testing binary addition operation\n";
    std::cout<<"a11= "<<m4.getElem11()<<"\n";
    std::cout<<"a22= "<<m4.getElem12()<<"\n";
    std::cout<<"a21= "<<m4.getElem21()<<"\n";
    std::cout<<"a22= "<<m4.getElem22()<<"\n";
    
    Matrix2 m5;
    m5 = minv - m4;
    std::cout<<"Testing binary subtraction operation\n";
    std::cout<<"a11= "<<m5.getElem11()<<"\n";
    std::cout<<"a22= "<<m5.getElem12()<<"\n";
    std::cout<<"a21= "<<m5.getElem21()<<"\n";
    std::cout<<"a22= "<<m5.getElem22()<<"\n";

    Matrix2 m6;
    m6 = m1.scalarMult(0.5);
    std::cout<<"Testing scalar multiplication operation\n";
    std::cout<<"a11= "<<m6.getElem11()<<"\n";
    std::cout<<"a22= "<<m6.getElem12()<<"\n";
    std::cout<<"a21= "<<m6.getElem21()<<"\n";
    std::cout<<"a22= "<<m6.getElem22()<<"\n";

    return 0;
}