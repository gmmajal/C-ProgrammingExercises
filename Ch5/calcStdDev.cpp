#include <iostream>
#include <cmath>

double mean(double* arr, int size){
    double sum=0.0;
    for (int i=0;i<size;++i){
        sum+=arr[i];
    }
    return  sum/(double)size;
}

double stdDev(double* arr, int size){
    double arr_bar = mean(arr,size);
    double sum=0.0;
    for (int i=0;i<size;++i){
        sum+=arr[i]-arr_bar;
    }
    return sqrt(sum/(size-1));
}

int main(int argc, char* argv[]){
    double* x  = new double[3] {1.0,2.0,3.0};
    std::cout<<"The entries of the array are: "<<x[0]<<","<<x[1]<<","<<x[2]<<"\n";
    double x_bar = mean(x,3);
    double x_StdDev = stdDev(x,3);
    std::cout <<"The mean of this array is: "<<x_bar<<"\n";
    std::cout<<"The standard deviation of this array is: "<<x_StdDev<<"\n";
    delete[] x;
    return 0;
}