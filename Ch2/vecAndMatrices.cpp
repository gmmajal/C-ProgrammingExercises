#include <iostream>

int main(int argc, char* argv[]){
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double x[3],y[3],z[3];
    double A[3][3] = {{1.0, 5.0, 0.0},{7.0, 1.0, 2.0},{0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},{1.0, 0.0, 0.0},{4.0, 1.0, 0.0}};
    double C[3][3],D[3][3];

    double w[3];
    for (int i=0; i<3; i++){
        w[i] = u[i] - 3.0*v[i];
    }
    
    //assign values to x
    for (int i=0;i<3;++i){
        x[i]=u[i]-v[i];
    }
    //assign values to y
    for (int i=0;i<3;++i){
        y[i] = (A[i][0]*u[0]) + (A[i][1]*u[1]) + (A[i][2]*u[2]);
    }
    //assign values to z
    for (int i=0;i<3;++i){
        z[i]=y[i]-v[i];
    }
    //assign values to C
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            C[i][j]= (4*A[i][j]) - (3*B[i][j]);
        }
    }
    //assign values to D
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            double sum=0.0;
            for (int k=0;k<3;++k){
                sum+=A[i][k]*B[k][j];
            }
            D[i][j]=sum;
        }
    }

    std::cout<<"\n";
    std::cout<<"Printing values for vector x\n";
    //print out the values for x
    for (int i=0;i<3;++i){
        std::cout<<"x["<<i<<"] is "<<x[i]<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"Printing values for vector y\n";
    //print out the values for y
    for (int i=0;i<3;++i){
        std::cout<<"y["<<i<<"] is "<<y[i]<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"Printing values for vector z\n";
    //print out the values for z
    for (int i=0;i<3;++i){
        std::cout<<"z["<<i<<"] is "<<z[i]<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"Printing values for matrix C\n";
    //print out the values for C
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            std::cout<<"C["<<i<<","<<j<<"] is "<<C[i][j]<<"\n";
        }
    }
    std::cout<<"\n";
    std::cout<<"Printing values for matrix D\n";
    //print out the values for D
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            std::cout<<"D["<<i<<","<<j<<"] is "<<D[i][j]<<"\n";
        }
    }
    return 0;
}