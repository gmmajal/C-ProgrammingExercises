#include <iostream>

int main(int argc, char *argv[]){
    double a=1.5;
    double b=3.6;
    double c=a+b;
    double d=a*b;

    double mat[2][2]={{a,b},{c,d}};

    std::cout<<"The contents of the matrix rowise are as follows:\n";
    std::cout<<mat[0][0]<<" "<<mat[0][1]<<"\n";
    std::cout<<mat[1][0]<<" "<<mat[1][1]<<"\n";

    return 0;
}