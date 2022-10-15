#include <iostream>
#include <fstream>
#include <cassert>


int main(int argc, char* argv[]){
    int N = atof(argv[1]);
    assert(N>1);
    int a=0,b=1;
    double x[N],y[N];
    double h = (double) (b-a)/(N-1) ;
    std::cout<<"h = "<<h<<"\n";
    //set initial value
    y[0] = 1;
    x[0] = 0*h;
    for (int i=0;i<N-1;++i){
        x[i+1]= (i+1)*h;
        y[i+1]= (double) y[i]/(1+h);
    }
    std::ofstream writeXYData ("xy.dat");
    assert(writeXYData.is_open());
    writeXYData.setf(std::ios::scientific);
    for (int i=0;i<N;++i){
        writeXYData<<x[i]<<" "<<y[i]<<"\n";
    }
    writeXYData.close();
    return 0;
}