#include <iostream>
#include <cmath>

/**
* Partial pivoting is performed by the solver. 
* It is assumed that the system is non singular.
*/

/** test cases
 * For n=2 
 *  use  A[0][0]=2.0;A[0][1]=4.0;A[1][0]=5.0;A[1][1]=3.0;
 *       b[0] =4 ; b[1]=3;
 * 
 * For n=3
 * use A[0][0]=1.0;A[0][1]=1.0;A[0][2]=1.0;
 *     A[1][0]=1.0;A[1][1]=1.0;A[1][2]=2.0;
 *     A[2][0]=0.0;A[2][1]=5.0;A[2][2]=1.0;
 *     b[0] = 6; b[1]=9; b[2]=13;
**/

void SolveLinearSystem(double** A, double* x, double* b, int n);
void SelectPivotAndSwapRows(double** A, double* b, int n, int idx);
void RowEchelon(double** A, double* b, int n, int idx);
void BackSub(double** A, double*x, double* b, int n);

int main(){
    int n=2;
    double **A= new double* [n];
    for (int i=0;i<n;++i){
        A[i]= new double[n];
    }
    
    A[0][0]=0.0;A[0][1]=2.0;
    A[1][0]=1.0;A[1][1]=1.0;
    double* b =  new double [n];
    double* x = new double [n];
    b[0]=4; b[1]= 3;
    SolveLinearSystem(A,x,b,n);
    std::cout<<"The values of x are x1: "<<x[0]<<" and x2: "<<x[1]<<"\n";
    for (int i=0;i<n;++i){
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] x;
    return 0;
}

void SolveLinearSystem(double** A, double* x, double* b, int n){
    for (int i=0;i<n-1;++i){
        RowEchelon(A, b, n, i);
    }
    BackSub(A, x, b, n);
}

void SelectPivotAndSwapRows(double** A, double* b, int n, int idx){
    int pvtIdx = idx; 
    double piv=A[idx][idx];
    for (int i=idx;i<n-1;++i){
        if( fabs(piv) > fabs(A[i+1][idx])){
             
        }else{
            piv = A[i+1][idx];
            pvtIdx = i+1;
        }
    }
    /*Swap Matrix rows*/
    double tmp;
    for (int j=0;j<n;++j){
        tmp = A[idx][j];
        A[idx][j] = A[pvtIdx][j];
        A[pvtIdx][j] = tmp;  
    }
    /*Swap rows for vector b*/
    tmp=b[idx];
    b[idx]=b[pvtIdx];
    b[pvtIdx]=tmp;
}

void RowEchelon(double** A, double* b, int n, int idx){
    SelectPivotAndSwapRows(A, b, n, idx);
    double m;
    for (int i=idx+1;i<n;++i){
        m = A[i][idx]/A[idx][idx];
        for(int j=idx;j<n;++j){
            A[i][j] = A[i][j]-m*A[idx][j];
        }
        b[i]= b[i]-m*b[idx];
    }
}

void BackSub(double** A, double*x, double* b, int n){
    x[n-1] = b[n-1]/A[n-1][n-1];
    double tot;
    for (int k=n-2;k>-1;--k){
        tot=0.0;
        for(int i=k+1;i<n;++i){
            tot+= A[k][i]*x[i];
        }
        x[k]=(b[k]-tot)/A[k][k];
    }
}