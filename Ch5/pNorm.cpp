#include <iostream>
#include <cmath>

double CalculateNorm(double* x, int vecSize, int p=2){
    double sum = 0.0;

    //Loop over elems x_i of x, incrementing sum by |x_i|**p
    for (int i=0; i<vecSize; i++){
        double temp = fabs(x[i]);
        sum += pow(temp, p);
    }

    //Return p-th root of sum
     return pow(sum, 1.0/p);
}

int main(){
    int n=2;
    double* vec= new double[n];
    vec[0] = 1.0;
    vec[1] = 1.0;
    double norm2 = CalculateNorm(vec,n);
    std::cout<<"The calculated norm is "<<norm2<<"\n";
    return 0;
}