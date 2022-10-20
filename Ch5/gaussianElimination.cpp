#include <iostream>

/**
* it is assumed that the system is  
* 1) is non singular
* 2) does not require pivoting
*/

/** test cases
 * For n=2 
 *  use  A[0][0]=2.0;A[0][1]=4.0;A[1][0]=5.0;A[1][1]=3.0;
*        b[0] = 10; b[1]=11;
 * 
 * For n=3
 * use A[0][0]=2.0;A[0][1]=4.0;A[0][2]=3.0;
 *     A[1][0]=5.0;A[1][1]=3.0;A[1][2]=1.0;
 *     A[2][0]=1.0;A[2][1]=2.0;A[2][2]=2.0;
 *     b[0] = 19.0; b[1]=14.0; b[2]=11;
**/

void SolveLinearSystem(double** A, double* x, double* b, int n);
void RowEchelon(double** A, double* b, int n, int idx);
void BackSub(double** A, double* b, double* x, int n);

int main(int argc, char* argv[]){
    int n=3;
    double **A= new double* [n];
    for (int i=0;i<n;++i){
        A[i]= new double[n];
    }
    
    A[0][0]=2.0;A[0][1]=4.0;A[0][2]=3.0;
    A[1][0]=5.0;A[1][1]=3.0;A[1][2]=1.0;
    A[2][0]=1.0;A[2][1]=2.0;A[2][2]=2.0;
    double* b =  new double [n];
    double* x = new double [n];
    b[0]=19;b[1]=14;b[2]= 11;
    SolveLinearSystem(A,x,b,n);
    std::cout<<"The values of x are x1: "<<x[0]<<", x2: "<<x[1]<<" and x3: "<<x[2]<<"\n";
    for (int i=0;i<n;++i){
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] x;
    return 0;
}

void SolveLinearSystem(double** A, double* x, double* b, int n){
    for(int i=0;i<n-1;++i){
        RowEchelon(A,b,n,i);
    }
    BackSub(A,b,x,n);
}

void RowEchelon(double** A, double* b, int n, int idx){
    double m;
    for (int i=idx+1;i<n;++i){
        m = A[i][idx]/A[idx][idx];
        for(int j=idx;j<n;++j){
            A[i][j] = A[i][j]-m*A[idx][j];
        }
        b[i]= b[i]-m*b[idx];
    }
}

void BackSub(double** A, double* b, double* x, int n){
    x[n-1] = b[n-1]/A[n-1][n-1];
    double sum;
    for (int k=n-2;k>-1;--k){
        sum=0.0;
        for(int i=k+1;i<n;++i){
            sum+= A[k][i]*x[i];
        }
        x[k]=(b[k]-sum)/A[k][k];
    }
}