#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[]){
    double x[4]={0.0,1.0,1.0,0.0};
    double y[4]={0.0,0.0,1.0,1.0};
    std::ofstream writeFile("x_and_y.dat");
    assert(writeFile.is_open());
    writeFile.setf(std::ios::scientific);
    writeFile.setf(std::ios::showpos);
    writeFile.precision(10);
    writeFile<< x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<"\n";
    writeFile.flush();
    writeFile.precision(10);
    writeFile<< y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<"\n";
    writeFile.flush();
    writeFile.close();

}